n = int(input())
cnt=0
for i in range(n):
    s=input().split()
    if (s[-1]=="answer"):
        cnt+=(len(s[1]))
print(cnt)