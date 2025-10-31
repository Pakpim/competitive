#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=1<<20 +5;
ll x[45],y[45],ans[45];
map<tuple<ll,ll,ll>,ll> m;
vector<tuple<ll,ll,ll>> v1;
vector<pair<tuple<ll,ll,ll>,ll>> v2;
int pc[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    for (int i=1;i<N;i++) pc[i]=pc[i-(i&-i)]+1;
    int n,mid,tx,ty;
    cin >> n >> tx >> ty;
    mid=n/2;
    for (int i=0;i<n;i++) cin >> x[i] >> y[i];
    for (int i=0;i<(1<<mid);i++){
        ll nx=0,ny=0;
        for (int j=0;j<mid;j++){
            if (i&1<<j) nx+=x[j],ny+=y[j];
        }
        // m[{nx,ny,pc[i]}]++;
        v1.emplace_back(nx,ny,pc[i]);
    }
    sort(v1.begin(),v1.end());
    for (int i=0;i<v1.size();i++){
        if (v2.empty() || v2.back().first!=v1[i]){
            v2.emplace_back(v1[i],1);
        }
        else {
            v2.back().second++;
        }
    }
    for (int i=0;i<1<<(n-mid);i++){
        ll nx=0,ny=0;
        for (int j=0;j<n-mid;j++){
            if (i&1<<j) nx+=x[j+mid],ny+=y[j+mid];
        }
        for (int j=0;j<=mid;j++){
            // if (m.count({tx-nx,ty-ny,j})) ans[pc[i]+j]+=m[{tx-nx,ty-ny,j}];
            pair<tuple<ll,ll,ll>,ll> tg= {{tx-nx,ty-ny,j},0};
            auto it=lower_bound(v2.begin(),v2.end(),tg);
            if (it!=v2.end() && it->first==tg.first) ans[pc[i]+j]+=it->second;
        }
    }
    for (int i=1;i<=n;i++) cout << ans[i] << '\n';
}