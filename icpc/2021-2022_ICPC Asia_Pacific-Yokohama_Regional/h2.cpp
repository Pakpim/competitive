#include <bits/stdc++.h>
using namespace std;

using db=double;
using bts=bitset<10>;
const int SZ=105,N=35;
string s[N];
bool ok[N][N],f[N];
bts bt[N];
int sz,n;
db ans=0,ans2=0;

void cal2 (){
    for (int i=0;i<1<<n;i++){
        if (!i) continue;
        bts tmp;
        db nv=0,tmp2=-1;
        for (int j=0;j<n;j++) tmp[j]=0;
        for (int j=0;j<n;j++){
            if (i&1<<j){
                tmp2=-tmp2;
                tmp|=bt[j];
            }
        }
        nv=tmp2/pow(4.0,tmp.count());
        // cout << bitset<3>(i) << " = " << tmp2 << ' ' << tmp << ' ' << nv << '\n';
        ans2+=nv;
    }
}

void solve (){
    cin >> sz >> n;
    for (int i=0;i<n;i++) cin >> s[i],f[i]=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<sz;j++) bt[i][j]=(s[i][j]!='?');
    }
    for (int i=0;i<n;i++) for (int j=0;j<n;j++) ok[i][j]=1;
    for (int i=0;i<n;i++){
        for (int j=0;j<i;j++){
            if (f[i] || f[j]) continue;
            string tmp="";
            for (int k=0;k<sz;k++){
                if (s[i][k]!=s[j][k] && s[i][k]!='?' && s[j][k]!='?'){
                    ok[i][j]=ok[j][i]=0;
                }
                if (!ok[i][j]) break;
                if (s[i][k]=='?' || s[j][k]=='?') tmp+='?';
                else tmp+=s[i][k];
            }
            if (tmp==s[i]) f[j]=1;
            else if (tmp==s[j]) f[i]=1;
        }
    }
    db sum=0.0;
    for (int i=0;i<n;i++){
        if (f[i]) continue;
        int cnt=0;
        for (int j=0;j<sz;j++) if (!bt[i][j]) cnt++;
        sum+=pow(4.0,cnt);
    }
    ans=pow(4.0,-n)*sum;
    db er=1.0/db(n)*0.05;
    // cal2();
    cout << ans;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}