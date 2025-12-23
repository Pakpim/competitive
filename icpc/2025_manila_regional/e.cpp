#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=105, inf=1e9;
int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

void solve(){
    int r,c;
    cin >> r >> c;
    string a[r], b[r];
    for (int i=0;i<r;i++) cin >> a[i];
    for (int i=0;i<r;i++) cin >> b[i];
    queue<tuple<int,int,int,int,int>> q;
    int dis[r][c][r][c];
    for (int i=0;i<r;i++) for (int j=0;j<c;j++) for (int k=0;k<r;k++) for (int l=0;l<c;l++) dis[i][j][k][l]=inf;
    int sar, sac, sbr, sbc;
    for (int i=0;i<r;i++) for (int j=0;j<c;j++){
        if (a[i][j]=='S'){
            sar=i; sac=j;
            break;
        }
    }
    for (int i=0;i<r;i++) for (int j=0;j<c;j++){
        if (b[i][j]=='S'){
            sbr=i; sbc=j;
            break;
        }
    }
    q.emplace(sar,sac,sbr,sbc,0);
    while (!q.empty()){
        auto [ar,ac,br,bc,nd]=q.front();
        q.pop();
        if (b[br][bc]=='D'){
            cout << nd << '\n';
            return;
        }
        if (dis[ar][ac][br][bc]<=nd) continue;
        dis[ar][ac][br][bc]=nd;
        for (int i=0;i<4;i++){
            int xar=ar+d[i][0], xac=ac+d[i][1];
            if (xar<0 || xac<0 || xar>=r || xac>=c || a[xar][xac]=='X') continue;
            int xbr=br+d[i][0], xbc=bc+d[i][1];
            if (xbr<0 || xbc<0 || xbr>=r || xbc>=c || b[xbr][xbc]=='X') xbr=br, xbc=bc;
            q.emplace(xar,xac,xbr,xbc,nd+1);
        }
    }
    cout << "-1\n";
    return;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;;
    cin >> t;
    while (t--){
        solve();
    }
}