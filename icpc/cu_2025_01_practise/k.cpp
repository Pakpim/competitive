#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll N=1e5+5;
ll cnt[N],dp[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        int a;
        cin >> a;
        cnt[a]++;
    }
    for (ll i=1;i<N;i++){
        ll nv = i*cnt[i];
        if (i>1) nv+=dp[i-2];
        dp[i]=max(dp[i-1],nv);
    }
    cout << dp[N-1];
}