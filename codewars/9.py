n=int (input())
print("+"+"-"*n+"+"+"-"*n+"+")
for i in range (n):
    s="|"
    s+=' '*(i)
    s+='\\'
    s+=' '*(n-i-1)
    s+='|'
    s+=' '*(n-i-1)
    s+="/"
    s+=' '*(i)
    s+="|"
    print(s)
print("+"+"-"*n+"+"+"-"*n+"+")
for i in range (n-1,-1,-1):
    s="|"
    s+=' '*(i)
    s+='/'
    s+=' '*(n-i-1)
    s+='|'
    s+=' '*(n-i-1)
    s+="\\"
    s+=' '*(i)
    s+="|"
    print(s)
print("+"+"-"*n+"+"+"-"*n+"+")