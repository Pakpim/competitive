#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=1e6+5;
bool f[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int l,r, mx=0;
    deque<int> ans;
    cin >> l >> r;
    for (ll i=2;i<N;i++){
        if (f[i]) continue;
        for (ll j=i*i;j<N;j+=i) f[j]=1;
        int lb=l, rb=r;
        if (lb%i) lb+=i-(l%i);
        if (rb%i) rb-=l%i;
        if (lb>r || rb<l) continue;
        int nv=(rb-lb)/i +1;
        if (nv>mx){
            mx=nv;
            ans.clear();
        }
        if (nv==mx){
            ans.emplace_front(i);
        }
    }
    cout << mx << ' ' << ans.size() << '\n';
    for (auto e:ans) cout << e << ' ';
}