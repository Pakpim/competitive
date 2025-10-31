#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using bts=bitset<5>;
const ll N=2e5+5;
int a[N],ss[N];
vector<int> v[35];
bool db=0;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while (t--){
        ll n,q;
        cin >> n >> q;
        for (int i=1;i<=n;i++) cin >> a[i];
        for (int i=0;i<30;i++) v[i].clear();
        ss[n+1]=0;
        for (int i=n;i>0;i--) {
            ss[i]=ss[i+1]^a[i];
            for (int j=0;j<30;j++){
                if (a[i]>>j&1){
                    v[j].emplace_back(-i);
                }
            }
        }
        ss[0]=ss[1];
        ss[n+2]=0;
        for (int i=0;i<30;i++) v[i].emplace_back(0);
        if (db){
            for (int i=1;i<=n;i++) cout << bts(ss[i]) << ' ';
            cout << '\n';
            for (int i=1;i<=n;i++) cout << bts(a[i]) << ' ';
            cout << '\n';
            for (int i=5;i>0;i--){
                cout << i << " => ";
                for (auto e:v[i]) cout << -e << ' ';
                cout << '\n';
            }
        }
        while (q--){
            int x,l=0,r=n,nb=29;
            cin >> x;
            if (db) cout << "=>" << bts(x) << '\n';
            while (nb>=0){
                if (x>>nb&1){
                    auto it=upper_bound(v[nb].begin(),v[nb].end(),-r-1);
                    if (db) cout << "!" << nb << ' ' << *it << ' ' << -r << '\n';
                    if (db){
                        cout << v[nb].size() <<  " --> ";
                        for (auto e:v[nb]) cout << e << ' ';
                    }
                    if (db) cout << "?? " << bts(x) << ' ' << r+1 << ' ' << bts(ss[r+1]) << ' ';
                    x^=ss[r+1];
                    r=max(r,l+1);
                    r=-(*it);
                    if (db) cout << r+1 << ' ' << bts(ss[r+1]) << '\n';
                    x^=ss[r+1];
                    if (r){
                        auto it2=upper_bound(v[nb].begin(),v[nb].end(),-r);
                        l=max(l,-(*it2));
                    }
                }
                else{
                    auto it=upper_bound(v[nb].begin(),v[nb].end(),-r-1);
                    l=max(l,-(*it));
                }
                if (db && nb<6)cout << "? " << nb << ' ' << l << ' ' << r << ' ' << bts(x) << '\n';
                nb--;
            }
            cout << n-l << ' ';
        }
        cout << '\n';
    }
}