
a=0

for i in range(2000,4001):
    s=str(i)
    cnt=0
    for e in s:
        cnt+=int(e)
    if (cnt==8 and (i-2000)%12==0):a+=1
    
print(a)