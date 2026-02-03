import sys

def interact(i) :
    print(i)
    sys.stdout.flush()
    re = input()
    return re == "Y"

t = int(input())
while (t > 0) :
    c = 0
    while (1) :
        re = interact(c%2)
        if (re) :
            if (c != re) : interact(1)
            break
        c = 1-c
    t -= 1

    p = 1
    cnt = 1
    while (1) :
        re = interact(1)
        if (p == re) : break
        p = re
        cnt += 1

    print(-1, cnt)
    sys.stdout.flush()