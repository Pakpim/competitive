#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=1e5+5;
int d[8][2]={{-1,-2},{-1,2},{1,-2},{1,2},{-2,-1},{-2,1},{2,-1},{2,1}};
int dis[10][10][10][10];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    for (int ir=1;ir<=8;ir++){
        for (int ic=1;ic<=8;ic++){
            for (int jr=1;jr<=8;jr++){
                for (int jc=1;jc<=8;jc++){
                    dis[ir][ic][jr][jc]=1e9;
                }
            }
        }
    }
    for (int ir=1;ir<=8;ir++){
        for (int ic=1;ic<=8;ic++){
            queue<tuple<ll,ll,ll>> q;
            q.emplace(ir,ic,0);
            while (!q.empty()){
                auto [nr,nc,nd]=q.front();
                q.pop();
                if (dis[ir][ic][nr][nc]<nd) continue;
                dis[ir][ic][nr][nc]=nd;
                for (int x=0;x<8;x++){
                    int xr = nr+d[x][0], xc = nc+d[x][1];
                    if (xr && xc && xr<9 && xc<9) q.emplace(xr,xc,nd+1);
                }
            }
        }
    }
    int t;
    cin >> t;
    while (t--){
        string a,b;
        cin >> a >> b;
        cout << dis[a[0]-'a'+1][a[1]-'0'][b[0]-'a'+1][b[1]-'0'] << '\n';
    }
}