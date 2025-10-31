#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=55,M=998244353;
ll ar[4][N],sz[4],h[4][N][N];

pair<bool,string> cal (int ns){
    string re="";
    bool f=0;
    for (int i=0;i<ns;i++) re+='z'+1;
    for (int t=0;t<4;t++){
        int id[3]={0,1,2};
        for (int i=t;i<3;i++) id[i]++;
        for (int i=0;i+ns<=sz[id[0]];i++){
            for (int j=0;j+ns<=sz[id[1]];j++){
                for (int k=0;k+ns<=sz[id[2]];k++){
                    if (h[id[0]][i][ns]!=h[id[1]][j][ns] || h[id[0]][i][ns]!=h[id[2]][k][ns] || h[id[1]][j][ns]!=h[id[2]][k][ns]){
                        continue;
                    }
                    bool ok=1;
                    string nv="";
                    for (int p=0;p<ns;p++){
                        if (ar[id[0]][i+p]!=ar[id[1]][j+p] || ar[id[0]][i+p]!=ar[id[2]][k+p] || ar[id[1]][j+p]!=ar[id[2]][k+p]){
                            ok=0;
                            break;
                        }
                        if (ar[id[0]][i+p]+'a'>re[p]){
                            ok=0;
                            break;
                        }
                        nv+='a'+ar[id[0]][i+p];
                    }
                    if (ok){
                        re=nv;
                        f=1;
                    }
                    // else{
                    //     cout << " <= " << h[id[0]][i][ns] << ' ' << h[id[1]][j][ns] << ' ' << h[id[2]][k][ns] << '\n';
                    // }
                }
            }
        }
    }
    return {f,re};
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    string s[4],ans="";
    for (ll t=0;t<4;t++){
        cin >> s[t];
        sz[t]=s[t].size();
        for (ll i=0;i<sz[t];i++){
            if (s[t][i]>='a' && s[t][i]<='z') ar[t][i]=s[t][i]-'a';
            else if (s[t][i]>='A' && s[t][i]<='Z') ar[t][i]=s[t][i]-'A';
            else exit(1);
        }
        for (ll ns=1;ns<=sz[t];ns++){
            for (ll l=0;l+ns-1<sz[t];l++){
                h[t][l][ns]=h[t][l][ns-1]*26+ar[t][l+ns-1];
            }
        }
    }
    int l=0,r=50,mid;
    while (l<=r){
        mid=(l+r)/2;
        auto [ok,nv]=cal(mid);
        if (ok){
            l=mid+1;
            if (ans.size()<nv.size()) ans=nv;
        }
        else{
            r=mid-1;
        }
    }
    cout << ans;
}