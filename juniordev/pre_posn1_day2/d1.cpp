#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const int N=1005;
int ar[N][N],n;
bool test =1;

bool ch (){
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            for (int k=1;k<i;k++) if (ar[i][j]==ar[k][j]) return 0;
            for (int k=1;k<j;k++) if (ar[i][j]==ar[i][k]) return 0;
            if (i==j) for (int k=1;k<min(i,j);k++) if (ar[i][j]==ar[i-k][j-k]) return 0;
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    // for (int z=1;z<=1000;z++){
        // n=z;
        if (n&1){
            for (int i=1;i<=n;i++){
                for (int j=1;j<=n;j++) ar[i][j]=(i+j)%n+1;
            }
        }
        else{
            if (n==2){
                cout << "-1";
                // continue;
                exit(0);
            }
            for (int i=1;i<n;i++){
                for (int j=1;j<n;j++) ar[i][j]=(i+j)%(n-1)+1;
            }
            for (int i=1;i<n;i++) {
                ar[i][n]=ar[n][i%(n-1)+1]=ar[i][i%(n-1)+1];
                ar[i][i%(n-1)+1]=n;
            }
            ar[n][n]=n;
        }
        // cout << n << ' ' << ch() << '\n';
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++) cout << ar[i][j] << ' ';
            cout << '\n';
        }
        // if (!ch) exit(1);
    // }
    return 0;
}