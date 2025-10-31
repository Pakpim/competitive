#include <map>
#include <iostream>
using namespace std;
using ll=long long;
const ll N=200005;
ll a[N];
map <ll,int> mp;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n,cnt=0;
        cin >> n;
        mp.clear();
        for (int i=0;i<n;i++) {
            cin >> a[i];
            mp[a[i]]++;
            // cout << " => " << a << ' ' << b << '\n';
        }
        for (auto [nv,nc]:mp){
            ll b=nv;
            for (int j=0;j<31;j++) b^=1<<j;
            cnt+=mp[nv];
            // cout << " => " << nv << ' ' << nc  << ' ' << b << ' ' << mp[b] << '\n';
            mp[b]=max(0,mp[b]-nc);
            mp[nv]=0;
        }
        cout << cnt << '\n';
    }

}
