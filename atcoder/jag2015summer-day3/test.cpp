#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=5e5+5;
ll a[N],b[N],n,m;
mt19937 rnd;

ll s1 (){
    ll r=0,c=0,sum=0;
    while (r<n || c<m){
        cout << r << ' ' << c << ' ' << a[r] << ' ' << b[c] << " :";
        if (a[r]-a[r+1]<=b[c]-b[c+1]){
            sum+=a[r];
            c++;
        }
        else{
            sum+=b[c];
            r++;
        }
        cout << " => " << r << ' ' << c << ' ' << sum << '\n';
    }
    return sum;
}

ll s2 (){
    vector<vector<ll>> dp(n+5,vector<ll>(m+5,1e18));
    for (int i=0;i<=n;i++){
        for (int j=0;j<=m;j++){
            dp[i+1][j+1]=min(dp[i][j+1]+b[j],dp[i+1][j]+a[i]);
            if (!i && !j) dp[i+1][j+1]=0;
            cout << dp[i+1][j+1] << ' ';
        }
        cout << '\n';
    }
    return dp[n+1][m+1];
}

int main (){
    // int t=100;
    // while (t--){
    //     n=rnd()%10;
    //     m=rnd()%10;
    //     for (int i=0;i<=n;i++) a[i]=rnd()%ll(50);
    //     for (int i=0;i<=m;i++) b[i]=rnd()%ll(50);
    //     a[n+1]=b[m+1]=1e18;
    //     ll a1=s1(),a2=s2();
    //     if (a1!=a2){
    //         cout << n << ' ' << m << '\n';
    //         for (int i=0;i<=n;i++) cout << a[i] << ' ';
    //         cout << '\n';
    //         for (int i=0;i<=m;i++) cout << b[i] << ' ';
    //         cout << '\n';
    //         cout << " = " << a1 << ' ' << a2 << '\n';
    //         break;
    //     }
    // }
    cin >> n >> m;
    for (int i=0;i<=n;i++) cin >> a[i];
    for (int i=0;i<=m;i++) cin >> b[i];
    a[n+1]=b[m+1]=1e18;
    cout << s1();
}

/*
12 2
34 85 4 91 29 85 98 3 35 65 40 26 39 
20 19 4

2 2
34 35 4 
41 29 35
*/