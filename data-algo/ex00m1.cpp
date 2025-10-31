#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using pi=pair<ll,ll>;
const int N=1000005;
ll t[N];
priority_queue <pi,vector<pi>,greater<pi>> pq;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> t[i];
    for (int i=1;i<=n;i++) pq.emplace(0,i);
    for (int i=1;i<=m;i++) {
        auto [nt,ni]=pq.top();
        pq.pop();
        cout << nt << '\n';
        pq.emplace(nt+t[ni],ni);
    }
}