#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=3e5+5,K=1000;
int a[N],qs[N],mn[2005];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,ans=-1e9;
    for (int i=-999;i<=999;i++) mn[i+K]=1e9;
    cin >> n;
    for (int i=1;i<=n;i++) {
        cin >> a[i];
        qs[i]=qs[i-1]+a[i];
        mn[a[i]+K]=min(mn[a[i]+K],qs[i-1]);
        ans=max(ans,qs[i]-mn[a[i]+K]);
    }
    cout << ans;
    
}