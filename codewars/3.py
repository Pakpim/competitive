cnt=0
h=297
w=210

while (h>2 or w>2):
    if (h>w): h/=2
    else: w/=2
    cnt+=1

print(cnt,h,w*2)