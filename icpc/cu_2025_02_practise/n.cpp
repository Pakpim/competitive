#include <bits/stdc++.h>
using namespace std;

using lll=__int128_t;
using ll=long long;
const ll N=1e5+5;
ll a[N],b[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) cin >> b[i];
    deque<pair<int,lll>> dq;
    dq.emplace_back(0,0);
    for (int i=1;i<n;i++){
        while (dq.size()>1){
            auto [i1,v1]=dq.front(); dq.pop_front();
            auto [i2,v2]=dq.front();
            if (lll(v2-v1)>lll(a[i])*(lll(b[i1])-lll(b[i2]))){
                dq.emplace_front(i1,v1);
                break;
            }
        }
        auto [fi,fv]=dq.front();
        ll nv = fv + b[fi]*a[i];
        while (dq.size()>1){
            auto [i1,v1]=dq.back(); dq.pop_back();
            auto [i2,v2]=dq.back();
            if ((nv-v2)*(lll(b[i2])-lll(b[i1]))>(v1-v2)*(lll(b[i2])-lll(b[i]))){
                dq.emplace_back(i1,v1);
                break;
            }
        }
        dq.emplace_back(i,nv);
    }
    cout << ll(dq.back().second);
}