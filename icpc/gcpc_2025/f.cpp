#include <bits/stdc++.h>
using namespace std;

string s[2505],s2[2505];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    // int mx=0;
    // for (int i=1;i<=2500;i++){
    //     int cnt=0;
    //     for (int j=1;j*j<=i;j++){
    //         if (i%j==0){
    //             cnt++;
    //             if (j!=i/j) cnt++;
    //         }
    //     }
    //     mx=max(mx,cnt);
    // }
    // cout << mx;
    int n,m;
    cin >> n >> m;
    int a=0;
    bool f=0;
    for (int i=0;i<n;i++) cin >> s[i],s2[i]=s[i];
    for (int i=0;i<n;i++){
        int cnt=0;
        for (int j=0;j<=m;j++){
            if (j==m || s[i][j]=='.'){
                // cout << " => " << i << ' ' << j << ' ' << cnt << '\n';
                if (cnt){
                    if (f) a=__gcd(a,cnt);
                    else a=cnt,f=1;
                }
                cnt=0;
            }
            else cnt++;
        }
    }
    for (int i=0;i<m;i++){
        int cnt=0;
        for (int j=0;j<=n;j++){
            if (j==n || s[j][i]=='.'){
                // cout << " => " << i << ' ' << j << ' ' << cnt << '\n';
                if (cnt){
                    if (f) a=__gcd(a,cnt);
                    else a=cnt,f=1;
                }
                cnt=0;
            }
            else cnt++;
        }
    }
    for (int p=a;p>0;p--){
        if (a%p!=0) continue;
        bool ok=1;
        int cnt=0;
        for (int i=0;i<n;i++){
            s[i]=s2[i];
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (s[i][j]=='.') continue;
                for (int k=0;k<p && k+i<n;k++){
                    for (int l=0;l<p && l+j<m;l++){
                        if (s[i+k][j+l]=='.') ok=0;
                        s[i+k][j+l]='.';
                    }
                }
            }
        }
        if (ok){
            cout << p;
            return 0;
        }
    }
}