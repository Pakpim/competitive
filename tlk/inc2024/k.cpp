#include <bits/stdc++.h>
using namespace std;

using ll=long long;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,s;
    cin >> n >> s;
    ll mn=s,mx=s,ans=1e18;
    vector<pair<ll,ll>> v[2];
    for (int i=0;i<n;i++){
        ll a,b;
        cin >> a >> b;
        mn=min({mn,a,b});
        mx=max({mx,a,b});
        if (a<s && s<b) v[0].emplace_back(s-a,b-s);
        if (b<s && s<a) v[1].emplace_back(s-b,a-s);
    }
    for (int t=0;t<2;t++){
        sort(v[t].begin(),v[t].end());
        vector<ll> smx(v[t].size()+5,0);
        for (int i=v[t].size()-1;i>=0;i--) smx[i]=max(smx[i+1],v[t][i].second);
        ll nmn=smx[0];
        for (int i=0;i<v[t].size();i++){
            ll nv=v[t][i].first+smx[i+1];
            // cout << " => " << v[t][i].first << ' ' << v[t][i].second  << ' ' << smx[i] << '\n';
            nmn=min(nmn,nv);
        }
        // cout << " = " << nmn << '\n';
        ans=min(ans,mx-mn+nmn);
        // cout << "----------------\n";
    }
    cout << ans*2;
}

/*
4 2
7 9
-1 4
7 -7
1 3
*/