#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=3e5+5;
ll ar[N],p[N],mx[N],mx2[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        ll n,ans=0;
        cin >> n;
        for (int i=1;i<=n;i++) cin >> ar[i];
        for (int i=1;i<=n;i++){
            p[i]=p[i-1];
            if (p[i-1]<ar[i]) p[i]++;
            if (p[i-1]>ar[i]) p[i]--;
            mx[i]=max(mx[i-1],p[i]);
            if (i!=n) ans=max(ans,mx[i]);
        }
        for (int i=2;i<=n;i++){
            mx2[i]=max(mx[i-2],mx2[i-1]);
            if (mx2[i]<ar[i]) mx2[i]++;
            if (mx2[i]>ar[i]) mx2[i]--;
        }
        ans=max(ans,mx2[n]);
        cout << ans << '\n';
    }
}