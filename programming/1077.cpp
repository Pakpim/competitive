#include <bits/stdc++.h>
using namespace std;

const int N=1005;
int ar[N][N];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    while (n--){
        int x,y;
        cin >> x >> y;
        x++,y++;
        ar[x][y]++;
    }
    for (int i=1;i<N;i++){
        for (int j=1;j<N;j++){
            ar[i][j]+=ar[i-1][j]+ar[i][j-1]-ar[i-1][j-1];
        }
    }
    while (m--){
        int x,y,k;
        cin >> x >> y >> k;
        x++,y++;
        int xx=min(N-1,x+k),xy=min(N-1,y+k),nx=max(0,x-k-1),ny=max(0,y-k-1);
        cout << ar[xx][xy]-ar[xx][ny]-ar[nx][xy]+ar[nx][ny] << '\n';
    }
}