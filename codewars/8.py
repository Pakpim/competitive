
cnt=0
for a in range(10):
    for b in range(20):
        for c in range(20):
            for d in range(20):
                if (a*8.5+b*6+c*4+d*3==55.5):
                    cnt+=1
print(cnt)