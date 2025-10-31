#include <bits/stdc++.h>
using namespace std;

const int N=505,H=1000005,M=1e9+7;
int h[N], C[N][N], P[N][N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin >> n >> k;
    for (int i=1;i<=n;i++) cin >> h[i];
    for (int i=1;i<=k;i++){
        C[i][0] = 1;
        for (int j=1;j<=n;j++){
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % M;
        }
    }
}