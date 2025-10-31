l = ["BANGKOK", "ALGIERS", "ISTANBUL", "NASSAU", "JEDDAH", "WINNIPEG", "GUATEMALA CITY", "YASUJ", "EDMONTON", "FECAMP", "ROME", "PLOVDIV", "OSAKA", "UTRECHT", "DAR ES SALAAM", "KUALA LUMPUR", "MAZAR E SHARIF", "SHANGHAI", "TOKYO", "LUCKNOW", "HYDERABAD"]
n=l[0]
f=1
while f:
    f=0
    for e in l:
        if n[-1]==e[0]:
            n=e
            f=1
            break
print(n)
