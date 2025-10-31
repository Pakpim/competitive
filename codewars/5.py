
n=200005
f= [0]*n
p=[]

for i in range (2,n):
    if (f[i]==1): continue
    p.append([abs(123456-i),i])
    for j in range(i,n,i):
        f[j]=1

print(p)
p.sort()
print(p[0][1]+p[1][1]+p[2][1])
