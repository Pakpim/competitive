#include <bits/stdc++.h>
using namespace std;

using ll=long long;
string a[500];
ll dp[500][500];

int main (){
    ifstream fin;
    fin.open("7.txt");
    string s;
    ll idx=1, n, m;
    while (fin >> s){
        a[idx++]='.'+s+'.';
    }
    n=idx-1;
    m=a[1].size()-2;
    for (int i=0;i<=m+1;i++) a[0]=a[0]+'.';
    for (int i=0;i<=m+1;i++) a[n+1]=a[n+1]+'.';
    for (int i=0;i<=m+1;i++) dp[n][i]=1;
    for (int i=n-1;i>0;i--){
        for (int j=1;j<=m;j++){
            if (a[i][j]=='^') dp[i][j]=dp[i+1][j-1]+dp[i+1][j+1];
            else dp[i][j]=dp[i+1][j];
        }
    }
    ll ans=0;
    for (int i=1;i<=m;i++) if (a[1][i]=='S') ans=dp[1][i];
    cout << ans;
}