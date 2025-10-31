#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=15;
int r,c,d[3][2]={{0,1},{1,0},{-1,0}};
char a[N*N];
bool f[N][N];

void rec(int nr,int nc,int p){
    if (nr==r && nc== c){
        for (int i=0;i<p;i++) cout << a[i];
        cout << '\n';
        return;
    }
    for (int i=0;i<3;i++){
        int xr=nr+d[i][0], xc=nc+d[i][1];
        if (xr && xc && xr<=r && xc<=c && !f[xr][xc]){
            f[xr][xc]=1;
            cout << nr << ' ' << nc << ' ' << i << " => " << xr << ' ' << xc << ' ' << p << '\n';
            a[p]='A'+i;
            rec(xr,xc,p+1);
            f[xr][xc]=0;
        }
    }
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> r >> c;
    for (int i=1;i<=r;i++) for (int j=1;j<=c;j++) cin >> f[i][j];
    f[1][1]=1;
    rec(1,1,0);
    cout << "DONE";
}