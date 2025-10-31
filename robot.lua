function sysCall_init()
         
    -- This is executed exactly once, the first time this script is executed
    bubbleRobBase=sim.getObjectHandle(sim.handle_self) -- this is bubbleRob's handle
    leftMotor=sim.getObjectHandle("bubbleRob_leftMotor") -- Handle of the left motor
    rightMotor=sim.getObjectHandle("bubbleRob_rightMotor") -- Handle of the right motor
    noseSensor=sim.getObjectHandle("bubbleRob_sensingNose") -- Handle of the proximity sensor
    robot = sim.getObjectHandle('bubbleRob')
    minMaxSpeed={0*math.pi/180,300*math.pi/180} -- Min and max speeds for each motor
    

    -- Create the custom UI:
    xml = '<ui title="'..sim.getObjectName(bubbleRobBase)..' speed" closeable="false" resizeable="false" activate="false">'..[[
                <hslider minimum="0" maximum="100" on-change="speedChange_callback" id="1"/>
            <label text="" style="* {margin-left: 300px;}"/>
        </ui>
        ]]
    ui=simUI.create(xml)
    speed=(minMaxSpeed[1]+minMaxSpeed[2])*0.5
    simUI.setSliderValue(ui,1,100*(speed-minMaxSpeed[1])/(minMaxSpeed[2]-minMaxSpeed[1]))

    -- discs distance calculation
    treshold = 0.1
    discs = {
             sim.getObjectHandle('Disc1'),
             sim.getObjectHandle('Disc2'),
             sim.getObjectHandle('Disc3'),
             sim.getObjectHandle('Disc4'),
             sim.getObjectHandle('Disc5'),
           }
    
        
    pos = { {  1, 2 },
            { -3, 4 },
            {  6, 4 },
            {  2,-3 },
            { -2,-2 },
          }
  timestamp  = {}
  for i,h in ipairs(discs) do
    sim.setShapeColor(h,nil,sim.colorcomponent_ambient_diffuse,{.3,.4,.9})
    timestamp[i] = nil
    -- the next line set the position to pos
    -- sim.setObjectPosition(h,-1,{pos[i][1], pos[i][2], 0.002})

  end
    
end
function speedChange_callback(ui,id,newVal)
    speed=minMaxSpeed[1]+(minMaxSpeed[2]-minMaxSpeed[1])*newVal/100
end

function sysCall_actuation() 
    sim.setJointTargetVelocity(leftMotor,speed)
    sim.setJointTargetVelocity(rightMotor,speed)
    -- write your code only here
    -- you can create more function
    -- YOU CAN  use api that get the robot position  
    -- such as sim.getObjectPosition and sim.getObjectOrientation
    
    ----------------------------------------------------------------
    -- One-time controller setup (kept across calls in globals)
    ----------------------------------------------------------------
    if not CL then
        CL = {
            -- Robot geometry (tune to your model):
            R = 0.04,        -- [m] wheel radius
            B = 0.18,        -- [m] track width (wheel center-to-center)

            -- PID-like gains & limits:
            Kp_v = 1.2,      -- linear speed gain on distance
            Kp_w = 3.0,      -- proportional on heading error
            Ki_w = 0.4,      -- integral on heading error (optional, set 0.0 to disable)
            Kd_w = 0.2,      -- derivative on heading error (optional, set 0.0 to disable)
            V_MAX = 0.22,    -- [m/s] max linear speed
            W_MAX = 2.5,     -- [rad/s] max angular speed

            -- Behavior knobs:
            SLOW_DIST = 0.35,  -- [m] start tapering v near waypoint
            GOAL_TOL  = 0.10,  -- [m] consider disc reached
            FACE_ONLY = math.rad(90), -- if |heading error| > this, freeze forward v to help turning

            -- State:
            wp = 1,          -- Disc index: 1..5
            done = false,
            iw = 0.0,        -- integral of heading error
            ew_prev = 0.0,   -- previous heading error for derivative
            t_prev = sim.getSimulationTime(),
        }

        -- Helpers local to this closure:
        function CL.wrapPi(a)
            while a >  math.pi do a = a - 2*math.pi end
            while a < -math.pi do a = a + 2*math.pi end
            return a
        end
        function CL.clamp(x, lo, hi)
            if x < lo then return lo end
            if x > hi then return hi end
            return x
        end
        function CL.wheelsFromVW(v,w)
            local vl = v - 0.5*w*CL.B
            local vr = v + 0.5*w*CL.B
            return vl/CL.R, vr/CL.R
        end
    end

    ----------------------------------------------------------------
    -- Stop if already finished
    ----------------------------------------------------------------
    if CL.done then
        sim.setJointTargetVelocity(leftMotor,  0.0)
        sim.setJointTargetVelocity(rightMotor, 0.0)
        return
    end

    ----------------------------------------------------------------
    -- Read robot pose (allowed in closed loop)
    ----------------------------------------------------------------
    local p = sim.getObjectPosition(robot, -1)      -- {x,y,z}
    local o = sim.getObjectOrientation(robot, -1)   -- {alpha,beta,gamma}
    local x, y, yaw = p[1], p[2], o[3]

    ----------------------------------------------------------------
    -- Current waypoint (disc) position
    ----------------------------------------------------------------
    local wpH = discs[CL.wp]
    local gp  = sim.getObjectPosition(wpH, -1)
    local gx, gy = gp[1], gp[2]

    ----------------------------------------------------------------
    -- Errors
    ----------------------------------------------------------------
    local dx, dy = gx - x, gy - y
    local rho    = math.sqrt(dx*dx + dy*dy)          -- distance to goal
    local th_g   = math.atan2(dy, dx)                -- desired heading
    local e_th   = CL.wrapPi(th_g - yaw)             -- heading error

    -- Reached current disc?
    if rho < CL.GOAL_TOL then
        CL.wp = CL.wp + 1
        CL.iw, CL.ew_prev = 0.0, 0.0                 -- reset I/D terms between waypoints
        if CL.wp > #discs then
            CL.done = true
            sim.setJointTargetVelocity(leftMotor,  0.0)
            sim.setJointTargetVelocity(rightMotor, 0.0)
            return
        end
        -- Recompute goal using same pose this tick
        wpH = discs[CL.wp]
        gp  = sim.getObjectPosition(wpH, -1)
        gx, gy = gp[1], gp[2]
        dx, dy = gx - x, gy - y
        rho    = math.sqrt(dx*dx + dy*dy)
        th_g   = math.atan2(dy, dx)
        e_th   = CL.wrapPi(th_g - yaw)
    end

    ----------------------------------------------------------------
    -- PID-like control law
    ----------------------------------------------------------------
    local t = sim.getSimulationTime()
    local dt = math.max(1e-3, t - CL.t_prev)

    -- Linear speed from distance (with near-goal taper)
    local v_cmd = CL.Kp_v * rho
    if rho < CL.SLOW_DIST then
        v_cmd = v_cmd * (rho / CL.SLOW_DIST)
    end
    v_cmd = CL.clamp(v_cmd, -CL.V_MAX, CL.V_MAX)

    -- Optional: if facing away too much, stop forward motion to turn in place
    if math.abs(e_th) > CL.FACE_ONLY then
        v_cmd = 0.0
    end

    -- Heading PID (P + I + D on e_th)
    CL.iw = CL.iw + e_th * dt
    -- Anti-windup: limit integral term in effect (roughly)
    local IW_LIM = CL.W_MAX / math.max(1e-6, CL.Ki_w)
    if CL.Ki_w > 0.0 then
        CL.iw = CL.clamp(CL.iw, -IW_LIM, IW_LIM)
    else
        CL.iw = 0.0
    end

    local de = (e_th - CL.ew_prev) / dt
    local w_cmd = CL.Kp_w * e_th + CL.Ki_w * CL.iw + CL.Kd_w * de
    w_cmd = CL.clamp(w_cmd, -CL.W_MAX, CL.W_MAX)

    CL.ew_prev = e_th
    CL.t_prev  = t

    ----------------------------------------------------------------
    -- Send wheel commands (only allowed actuator)
    ----------------------------------------------------------------
    local wl, wr = CL.wheelsFromVW(v_cmd, w_cmd)
    sim.setJointTargetVelocity(leftMotor,  wl)
    sim.setJointTargetVelocity(rightMotor, wr)
end

function sysCall_sensing()
  for i,h in ipairs(discs) do
    check_disc(i,h)
  end
end

function check_disc(idx,handle)
  r,d = sim.checkDistance(robot,handle,0)
  if d[7] < treshold then
    sim.setShapeColor(handle,nil,sim.colorcomponent_ambient_diffuse ,{1,.7,.4})
    if (timestamp[idx] == nil) then
      timestamp[idx] = sim.getSimulationTime()
      print("Check point "..idx.." at "..timestamp[idx])
    end
    
  end
end

function sysCall_cleanup() 
    for i,h in ipairs(discs) do
      sim.setShapeColor(h,nil,sim.colorcomponent_ambient_diffuse,{.3,.4,.9})
    end
    simUI.destroy(ui)
end 
