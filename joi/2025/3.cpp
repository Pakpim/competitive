#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=3e5+5;
vector<pair<ll,ll>> ev,v1,v2;
map<ll,ll> mp;
ll in[N],sp[N][25];

ll qu (ll l, ll r){
    int j=log2(r-l+1);
    return max(sp[l][j],sp[r-(1<<j)+1][j]);
}


int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,m,p;
    cin >> n >> m >> p;
    while (m--){
        ll u,v,c;
        ev.emplace_back(c,v);
    }
    sort(ev.begin(),ev.end());
    ll np=0,tmp=0;
    for (auto [nc,nn]:ev){
        if (in[nn]==0) tmp++;
        in[nn]++;
        while (in[ev[np].second]>1){
            in[ev[np].second]--;
            np++;
        }
        if (tmp==n){
            mp[nc]=max(mp[nc],ev[np].first);
        }
    }
    for (auto [k,v]:mp) v1.emplace_back(v,k),v2.emplace_back(k,v);
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    for (int i=0;i<v1.size();i++){
        sp[i][0]=v1[i].second-v1[i].first;
    }
    for (int i=1;i<25;i++){
        for (int j=0;j<v1.size();j++){
            sp[j][i]=min(sp[j][i-1],sp[min(int(v1.size()-1),j+1<<(i+1))][i-1]);
        }
    }
    ll q;
    cin >> q;
    while (q--){
        ll l,r,x;
        cin >> l >> r >> x;
        ll mn=1e18;
        auto it=lower_bound(v1.begin(),v1.end(),make_pair(l,0));
        if (it->second<=r){
            cout << "Yes\n";
            continue;
        }
        mn=it->second-r;
        it=upper_bound(v2.begin(),v2.end(),make_pair(r,1e18));
        if (it!=v2.begin()){
            it--;
            mn=min(mn,l-it->second);
        }
        int ql=1e9,bl=0,br=v1.size()-1,mid;
        while (bl<=br){
            mid=(l+r)/2;
            
        }
    }
}