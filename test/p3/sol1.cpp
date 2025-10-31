#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int T=100005,N=105;
ll b[T][N],dp[T][N];
bool b2[T][N];

int main (){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m,s;
  cin >> n >> m >> s;
  while (m--){
    int t,a;
    cin >> t >> a >> b[t][a];
  }
  b2[0][s]=1;
  for (int i=1;i<T;i++){
    for (int j=1;j<=n;j++){
      if (b2[i-1][j-1]) dp[i][j] =max(dp[i][j],dp[i-1][j-1]),b2[i][j]=1;
      if (b2[i-1][j]) dp[i][j] =max(dp[i][j],dp[i-1][j]),b2[i][j]=1;
      if (b2[i-1][j+1]) dp[i][j] =max(dp[i][j],dp[i-1][j+1]),b2[i][j]=1;
      if (b2[i][j]) dp[i][j]+=b[i][j];
    }
  }
  ll mx=0;
  for (int i=1;i<=n;i++) mx=max(mx,dp[T-1][i]);
  cout << mx;
}

/*
example1:
3 4 1
1 3 99
2 3 5
3 1 10
4 2 10

ans: 20

example2:
3 5 2
12 1 6
6 3 8
7 3 9
13 2 9
14 2 2

ans: 34

example3:
5 15 2
68 3 60
22 2 808
23 1 7
60 2 22
2 2 81
93 4 4
24 5 6
14 3 349
56 5 99
80 2 7
62 1 79
38 1 86
78 3 4
15 3 93
58 2 22

ans: 1699
*/