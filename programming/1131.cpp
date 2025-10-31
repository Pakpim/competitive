#include <bits/stdc++.h>
using namespace std;

const int N=1e6+5,M=2553;
int a[N],dp1[N],dp2[N],dp3[N];
int n;
string s;

int solve(){
    int c1=1,c2=0,tmp=1;
    dp1[1]=1;
    dp2[0]=1;
    dp2[1]=3;
    for (int i=2;i<=n;i++){
        dp1[i]=(((dp1[i-1]+dp1[i-2])%M)*2)%M;
        dp2[i]=(((dp1[i]+dp1[i-1])%M)*3)%M;
        dp3[i]=(((dp3[i-1]+dp1[i-2])%M)*3)%M;
        // cout << dp1[i] << ' ' << dp2[i] << ' ' << dp3[i] << '\n';
    }
    for (int i=0;i<n;i++){
        if (s[i]=='P') a[i]=0;
        if (s[i]=='R') a[i]=1;
        if (s[i]=='S') a[i]=2;
    }
    for (int i=0;i<n;i++){
        c1+=(a[i]*tmp)%M; c1%=M;
        tmp=(tmp*3)%M;
        for (int j=0;j<a[i];j++){
            int p=1;
            while (i+p<n && p<3 && a[i+p]==j) p++;
            if ((p==1 || p==2) && i) c2=(c2+dp1[i-1])%M;
            if (p==2) c2=(c2+dp1[i])%M;
            if (p==3) c2=(c2+dp2[i])%M;
            c2=(c2+dp3[i])%M;
            // cout << i << " = " << j << ' ' << p << ' ' << c2 << '\n';
        }
    }
    // cout << "?" << c1 << ' ' << c2 << '\n';
    return (((c1-c2)%M)+M)%M;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    bool test=0;
    n=10;
    if (!test) {
        cin >> n >> s;
        reverse(s.begin(),s.end());
        cout << solve();
    }
    else{
        int cnt=0;
        for (int i=0;;i++){
            int p=0;
            s="";
            int j=i;
            while (j && p<n) {
                if (j%3==0) s+='P';
                if (j%3==1) s+='R';
                if (j%3==2) s+='S';
                p++;
                j/=3;
            }
            while (p<n){
                s+='P';
                p++;
            }
            if (p==n && j) break;
            int dup=0,bv=-1;
            bool ok=1;
            for (int j=0;j<n;j++){
                if (s[j]!=bv){
                    bv=s[j];
                    dup=1;
                }
                else dup++;
                if (dup>2) ok=0;
            }
            if (!ok){
                cnt++;
            }
            else{
                int nv=(i+1-cnt)%M;
                int ans=solve();
                if (ans!=nv){
                    // reverse(s.begin(),s.end());
                    cout << "!" << i+1 << ' ' << cnt << '\n';
                    cout << n <<'\n' << s << '\n' << ans << " , " << nv <<'\n';
                    exit(0);
                }
                // cout << s << ' ' << nv << '\n';
            }
            // cout << i+1 << ' ' << cnt << ' ' << s << '\n';
        }
    }
}