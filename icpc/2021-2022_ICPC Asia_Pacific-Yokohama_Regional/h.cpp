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

void cal (int nn,int ni){
    if (ni==n){
        if (!nn) return;
        db nv=0,tmp2=-1;
        bts tmp;
        for (int i=0;i<sz;i++) tmp[i]=0;
        for (int i=0;i<n;i++){
            if (nn&1<<i){
                tmp2=-tmp2;
                tmp|=bt[i];
            }
        }
        nv=tmp2/pow(4.0,tmp.count());
        // cout << bitset<6>(nn) << " => " << tmp2 << ' ' << tmp << ' ' << nv << '\n';
        ans+=nv;
        return;
    }
    cal(nn,ni+1);
    int cnt=0;
    bool b=1;
    for (int i=0;i<n;i++){
        if (nn&1<<i){
            b&=ok[i][ni];
            cnt++;
        }
    }
    bts tmp;
    for (int i=0;i<sz;i++) tmp[i]=0;
    for (int i=0;i<n;i++){
        if (nn&1<<i){
            tmp|=bt[i];
        }
    }
    if (b && !f[ni] && 1.0/pow(4.0,tmp.count()+1)>ans*0.005){
        cal(nn|1<<ni,ni+1);
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
    cal(0,0);
    // cal2();
    cout << ans;// << ' ' << ans2;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}