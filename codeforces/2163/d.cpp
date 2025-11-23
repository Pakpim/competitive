#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using pll=pair<ll,ll>;
const ll N=2e5+5;
ll a[4][N],pmn[N],pmx[N],smn[N],smx[N];

int ask(int l,int r){
    int re;
    cout << "? " << l << ' ' << r << '\n';
    cout.flush();
    cin >> re;
    return re;
}

void ans(int x){
    cout << "! " << a << ' ';
    cout.flush();
}

void solve(){
    int n,q;
    cin >> n >> q;
    vector<pll> v;
    while (q--){
        int l,r;
        cin >> l >> r;
        v.emplace_back(l,r);
    }
    sort(v.begin(),v.end());
    vector<pll> v2;
    for (auto [l,r]:v){
        if (v2.empty() || v2.back().second<r){
            v2.emplace_back(l,r);
        } 
    }
    int l=0, r=v2.size()-1,mid;
    while (l<r){
        mid=(l+r)/2;
        int vl=ask(v2[l].first, v2[mid].second), vr=ask(v2[mid+1].first, v2[r].second);
        if (vl<vr){
            l=mid+1;
        }
        else{
            r=mid;
        }
    }
    int re=ask(v2[l].first, v2[l].second);
    ans(re);
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while (t--){
        solve();
    }
}