#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=1e6;
bool f[N];
vector<ll> prime;
ll  n,d,s,ans=1;

// max d =>
// ll cal (ll nn){
//     for (auto p:prime){
//         if (nn%p==0){
//             return nn/p*(p-1);
//         }
//     }
//     return nn-1;
// }

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    for (int i=2;i<N;i++){
        if (f[i]) continue;
        prime.emplace_back(i);
        for (int j=i*2;j<N;j+=i) f[j]=1;
    }
    cin >> n >> d >> s;
    n/=s;
    d/=s;
    ans=max(1ll,min(n,d+1));
    // cout << " => " << n << ' ' << d << ' ' << ans << '\n';
    for (auto p:prime){
        // ll l=1,r=n/p,mid;
        // while (l<=r){
        //     mid=l+(r-l)/2;
        //     if (mid*(p-1)<=d){
        //         ans=max(ans,mid*p);
        //         l=mid+1;
        //     }
        //     else r=mid-1;
        // }
        ans=max(ans,min(n/p,d/(p-1))*p);
    }
    cout << ans*s;
}