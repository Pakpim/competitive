#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=4e5+5,M=1e6+5;
ll a[N];
vector<ll> p;
map<ll,ll> mp;
bool f[M];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    for (ll i=2;i<M;i++){
        if (f[i]) continue;
        p.emplace_back(i);
        for (int j=i*2;j<M;j+=i) f[j]=1;
    }
    int t;
    cin >> t;
    while (t--){
        ll n,ans=0;
        cin >> n;
        mp.clear();
        for (int i=1;i<=n;i++){
            cin >> a[i];
            mp[a[i]]++;
        }
        while (!mp.empty()){
            auto it=mp.end();
            it--;
            auto [nv,nc]=*it;
            ans=max(ans,nv+nc);
            ll tmp=nv;
            for (auto np:p){
                if (tmp%np==0) mp[nv/np]+=nv;
                while (tmp%np==0){
                    tmp/=np;
                }
                if (tmp==1) break;
            }
            if (tmp>1) mp[tmp]++;
            mp.erase(it);
        }
        cout << ans << '\n';
    }
}