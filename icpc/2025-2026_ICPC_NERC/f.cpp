#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=3e5+5;
ll a[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,d;
    string s;
    cin >> n >> d;
    for (int i=1;i<=n;i++) cin >> a[i];
    cin >> s;
    vector<ll> vp,vn;
    for (int i=1;i<=n;i++){
        if (s[i-1]=='-') vn.emplace_back(a[i]);
        else vp.emplace_back(a[i]);
    }
    vp.emplace_back(-1e18);
    sort(vn.begin(), vn.end());
    sort(vp.begin(), vp.end());
    // for (auto e:vp) cout << e << ' ';
    // cout << '\n';
    ll sum=0;
    for (auto e:vn){
        auto it =upper_bound(vp.begin(),vp.end(), e+d);
        auto it2=upper_bound(vp.begin(),vp.end(), e-d-1);
        auto it3=lower_bound(vp.begin(), vp.end(), e);
        auto it4=upper_bound(vp.begin(), vp.end(), e);
        // cout << "? "  << *it2 << ' ' << it2-vp.begin() << '\n';
        it--, it2--, it4--;
        ll a=0,b=0;
        if ((*it3)==e){
            b=it4-it3+1;
        }
        if ((*it)!=-1e18){
            a=it-it2;
        }
        // cout << " => " << e << ' ' << a << ' ' << b << " : " << *it << ' ' << *it2 << ' ' << *it3 << ' ' << *it4 << '\n';
        sum+=a-b;
    }
    cout << sum;
}