#include <bits/stdc++.h>
using namespace std;

int ar[205][205];

void solve (int r,int c,bool test=0){
    if ((min(r,c)== 3 && max(r,c) < 6) || (min(r,c) == 4 && max(r,c) < 4) || min(r,c) < 3){
        if (!test) cout << "-1\n";
        return;
    }
    vector <tuple<int,int,int,int,int,int>> ans;
    int tr=r,tc=c;
    int nx=1;
    while (ans.size()*4<=(tr*tc)){
        if (r==3){
            ans.emplace_back(nx,2,1,1,0,1);
            ans.emplace_back(nx+c-1,2,1,1,c-5,0);
            ans.emplace_back(nx+2,1,0,1,1,c-4);
            ans.emplace_back(nx+3,3,1,0,2,c-5);
            break;
        }
        if (c==3){
            ans.emplace_back(nx+1,1,0,1,1,1);
            ans.emplace_back(nx+1,r,r-5,0,1,1);
            ans.emplace_back(nx,4,2,r-5,0,1);
            ans.emplace_back(nx+2,3,1,r-4,1,0);
            break;
        }
        if (r==4){
            ans.emplace_back(nx,3,1,1,0,c-3);
            ans.emplace_back(nx+1,1,0,1,1,c-3);
            ans.emplace_back(nx+c-2,4,1,0,c-3,1);
            ans.emplace_back(nx+c-1,2,1,1,c-3,0);
            break;
        }
        if (c==4){
            ans.emplace_back(nx+1,1,0,r-3,1,1);
            ans.emplace_back(nx,r-1,r-3,1,0,1);
            ans.emplace_back(nx+3,2,1,r-3,1,0);
            ans.emplace_back(nx+2,r,r-3,0,1,1);
            break;
        }
        if (r==5 && c==5){
            ans.emplace_back(nx,2,1,2,0,1);
            ans.emplace_back(nx+1,5,1,0,1,2);
            ans.emplace_back(nx+2,3,1,1,1,0);
            ans.emplace_back(nx+3,1,0,2,2,1);
            ans.emplace_back(nx+4,4,2,1,1,0);
            break;
        }
        if (r==5 && c==6){
            ans.emplace_back(nx,3,1,1,0,3);
            ans.emplace_back(nx+1,1,0,1,1,3);
            ans.emplace_back(nx+1,5,1,0,1,2);
            ans.emplace_back(nx+4,4,1,1,2,0);
            ans.emplace_back(nx+5,2,1,3,3,0);
            break;
        }
        if (c==5 && r==6){
            ans.emplace_back(nx,2,1,2,0,1);
            ans.emplace_back(nx+1,5,2,0,1,1);
            ans.emplace_back(nx+2,1,0,3,1,1);
            ans.emplace_back(nx+3,6,3,0,3,1);
            ans.emplace_back(nx+4,2,1,3,1,0);
            break;
        }
        if (r==5 && c==7){
            ans.emplace_back(nx,3,1,1,0,5);
            ans.emplace_back(nx+1,1,0,1,1,4);
            ans.emplace_back(nx+1,5,1,0,1,1);
            ans.emplace_back(nx+3,4,0,1,1,1);
            ans.emplace_back(nx+5,5,1,0,1,1);
            ans.emplace_back(nx+6,2,1,2,4,0);
            break;
        }
        if (c==5 && r==7){
            ans.emplace_back(nx,2,1,1,0,1);
            ans.emplace_back(nx,6,1,1,0,1);
            ans.emplace_back(nx+1,4,1,1,1,0);
            ans.emplace_back(nx+2,1,0,5,1,1);
            ans.emplace_back(nx+3,7,4,0,2,1);
            ans.emplace_back(nx+4,2,1,4,1,0);
            break;
        }
        ans.emplace_back(nx,r-1,r-2,1,0,1);
        ans.emplace_back(nx+2,r,1,0,1,c-4);
        ans.emplace_back(nx+c-1,r-1,r-2,1,c-4,0);
        r-=2;
        c-=2;
        nx++;
    }
    if (!test){
        cout << ans.size() << '\n';
        for (auto [x,y,u,d,l,r]:ans) cout << x << ' ' << y << ' ' << u << ' ' << l << ' ' << d << ' ' << r << '\n';
    }
    // if (!test) cout << '\n';
    // for (auto [x,y,u,d,l,r]:ans){
    //     for (int i=x-l;i<=x+r;i++) ar[y][i]++;
    //     for (int i=y-u;i<=y+d;i++) ar[i][x]++;
    //     ar[y][x]--;
    // }
    // for (int i=0;i<=tr+1;i++){
    //     for (int j=0;j<=tc+1;j++) {
    //         if ((i && j && i<=tr && j<=tc && ar[i][j]!=1) && test) {
    //             cout << " ! " << tr << ' ' << tc << '\n';
    //             exit(0);
    //         }
    //         if (!test) cout << ar[i][j] << ' ';
    //         ar[i][j]=0;
    //     }
    //     if (!test) cout << '\n';
    // }
    ans.clear();
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int r,c;
        cin >> r >> c;
        solve(r,c);
    }
    // for (int i=1;i<=200;i++){
    //     for (int j=1;j<=200;j++){
    //         solve(i,j,1);
    //     }
    // }
}