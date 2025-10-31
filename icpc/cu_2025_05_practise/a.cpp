#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=1e5+5;
ll c[N],dp[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) {
        int a;
        cin >> a;
        c[a]++;
    }
    dp[1]=c[1];
    for (int i=2;i<N;i++){
        dp[i]=max(dp[i-1],i*c[i]+dp[i-2]);
    }
    cout << dp[N-1];
}