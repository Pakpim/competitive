#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using ti=tuple<ll,ll,ll>;
const int N=2e5+5;
ll ar[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        ll n,l,r,ans=1e18;
        cin >> n >> l >> r;
        ll sz=r-l+1;
        for (int i=1;i<=n;i++) cin >> ar[i];
        priority_queue<ll> p;
        ll sum=0;
        for (int i=1;i<=r;i++){
            p.emplace(ar[i]);
            sum+=ar[i];
            if (p.size()>sz){
                sum-=p.top();
                p.pop();
            }
        }
        ans=min(ans,sum);
        while (!p.empty()) p.pop();
        sum=0;
        for (int i=l;i<=n;i++){
            p.emplace(ar[i]);
            sum+=ar[i];
            if (p.size()>sz){
                sum-=p.top();
                p.pop();
            }
        }
        ans=min(ans,sum);
        cout << ans << '\n';
    }
}