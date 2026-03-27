#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=3e5+5;
ll pos[N], qs[N], qss[N];
vector<ll> ap;

ll idx (ll np){
    return lower_bound(ap.begin(),ap.end(),np)-ap.begin()+1;
}

signed main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,m;
    cin >> n >> m;
    vector<tuple<ll,ll,ll>> q1(n);
    vector<tuple<ll,ll>> q2(m);
    for (auto &[l,r,w]:q1) {
        cin >> l >> r >> w;
        ap.emplace_back(l);
        ap.emplace_back(r+1);
    }
    for (auto &[s,h]:q2) {
        cin >> s >> h;
        s++;
        ap.emplace_back(s);
    }
    sort(ap.begin(),ap.end());
    ap.erase(unique(ap.begin(),ap.end()), ap.end());
    ll mx=idx(ap.back());
    for (auto e:ap) pos[idx(e)]=e;
    pos[mx+1]=ap.back()+1;
    for (auto [l,r,w]:q1){
        qs[idx(l)]+=w;
        qs[idx(r+1)]-=w;
    }
    for (ll i=1;i<=mx;i++) qs[i]+=qs[i-1];
    for (ll i=1;i<=mx;i++) qss[i]=qss[i-1]+qs[i]*(pos[i+1]-pos[i]);
    for (auto [s,h]:q2){
        ll l=idx(s), r=mx, mid, tg=1e9;
        while (l<=r){
            mid=l+(r-l)/2;
            if (qss[mid]-qss[idx(s)-1]>=h){
                tg=min(tg,mid);
                r=mid-1;
            }
            else l=mid+1;
        }
        if (tg==1e9){
            cout << "-1\n";
            continue;
        }
        ll ar=pos[tg+1]-1-(qss[tg]-qss[idx(s)-1]-h)/qs[tg];
        cout << ar-s+1 << '\n';
    }
}

/*
6 6
1 3 1
2 4 1
3 5 1
4 6 1
5 7 1
6 8 1
0 15
0 17
1 3
1 15
5 7
6 2

6 1
1 3 1
2 4 1
3 5 1
4 6 1
5 7 1
6 8 1
0 15
*/