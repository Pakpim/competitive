#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=105, M=15;
ll tg[N], ns[N], a[M], b[M], c[M], d[M];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i=0;i<n;i++){
        int s,t,w;
        cin >> s >> t >> w;
        tg[s]+=w; tg[t+1]-=w;
    }
    for (int i=0;i<m;i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
    for (int i=1;i<N;i++) tg[i]+=tg[i-1];
    int ans=1e9;
    for (int i=0;i<(1<<m);i++){
        for (int j=1;j<N;j++) ns[j]=0;
        int sum=0;
        for (int j=0;j<10;j++){
            if (i>>j&1){
                ns[a[j]]+=c[j];
                ns[b[j]+1]-=c[j];
                sum+=d[j];
            }
        }
        bool ok=1;
        for (int j=1;j<N;j++){
            ns[j]+=ns[j-1];
            if (ns[j]<tg[j]) ok=0;
        }
        if (ok) ans=min(ans,sum);
    }
    cout << ans;
}