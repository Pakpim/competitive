#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=4e5+5;
bool f[N];
vector<ll> p;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    for (ll i=2;i<N;i++){
        if (f[i]) continue;
        if (i*i<N) p.emplace_back(i);
        for (ll j=i*2;j<N;j+=i) f[j]=1;
    }
    // cout << " =? " << p.size() << '\n';
    // for (auto e:p) cout << e << ' '; cout << '\n';
    ll t;
    cin >> t;
    while (t--){
        ll n;
        ll ans=2,cnt=0;
        bool ok=1;
        vector<ll> ar;
        cin >> n;
        for (ll i=0;i<n;i++){
            ll v;
            cin >> v;
            if (!f[v]){
                cnt++;
                if (cnt<2) ans=v;
                else ok=0;
            }
            else{
                ar.emplace_back(v);
            }
        }
        for (auto e:ar){
            if (e%ans==0) continue;
            ll tmp=e,mn=e;
            for (auto np:p) {
                if (tmp%np==0){
                    mn=min(mn,np);
                    while (tmp%np==0) tmp/=np;
                }
            }
            if (tmp>1) mn=min(mn,tmp);
            if (mn*ans<=e || mn>=ans) continue;
            bool nok=0;
            tmp=e;
            for (auto np:p){
                while (tmp%np==0) tmp/=np;
            }
            if (tmp>1 && tmp>=ans) nok=1;
            for (auto np:p) {
                if (e%np==0 && np>=ans){
                    nok=1;
                }
            }
            ll pt=1;
            for (auto np:p){
                if (np!=2 && np<ans && e%np==0){
                    ll nv=(np-(ans%np))%np;
                    if (2*nv+2*ans <= e) nok=1;
                }
            }
            if (nok) continue;
            ok=0;
        }
        if (ok) cout << ans << '\n';
        else cout << "-1\n";
    }
}