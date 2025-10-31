#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll M=1e8+7;
ll a[4][4]={{1,0,1,0},
            {1,0,0,0},
            {0,1,0,1},
            {0,1,0,1}};

ll b[4][4]={{1,0,0,0},
            {0,1,0,0},
            {0,0,1,0},
            {0,0,0,1}};

ll tmp[4][4];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n;
    cin >> n;
    n-=2;
    while(n){
        if (n&1){
            for (int i=0;i<4;i++) for (int j=0;j<4;j++) tmp[i][j]=0;
            for (int i=0;i<4;i++) for (int j=0;j<4;j++) for (int k=0;k<4;k++) tmp[i][j]=((a[i][k]*b[k][j])%M+tmp[i][j])%M;
            for (int i=0;i<4;i++) for (int j=0;j<4;j++) b[i][j]=tmp[i][j];
        }
        for (int i=0;i<4;i++) for (int j=0;j<4;j++) tmp[i][j]=0;
        for (int i=0;i<4;i++) for (int j=0;j<4;j++) for (int k=0;k<4;k++) tmp[i][j]=((a[i][k]*a[k][j])%M+tmp[i][j])%M;
        for (int i=0;i<4;i++) for (int j=0;j<4;j++) a[i][j]=tmp[i][j];
        n>>=1;
    }
    ll sum=0;
    for (int i=0;i<4;i++) for (int j=0;j<4;j++) sum=(sum+b[i][j])%M;
    cout << sum;
}