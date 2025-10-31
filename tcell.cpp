#include <bits/stdc++.h>
using namespace std;

const int N=11;
bool f[N][N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    for (int i=0;i<N;i++) f[0][i]=f[i][0]=f[N-1][i]=f[i][N-1]=1;
    f[0][N/2]=f[0][N/2-1]=0;
    f[N-1][N/2]=f[N-1][N/2+1]=0;
    f[N-1][N/2]=f[N-1][N/2]=0;

    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) cout << f[i][j]; 
        cout << '\n';
    }
}