#include<bits/stdc++.h>
using namespace std;

using ll=long long; 

const int N=55;
int d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
string s[N];
bool f1[N][N], f2[N][N];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int r,c;
    cin >> r >> c;
    for (int i=0;i<r;i++) cin >> s[i];
    int sr,sc, tr,tc;
    for (int i=0;i<r;i++) for (int j=0;j<c;j++){
        if (s[i][j]=='S') sr=i, sc=j;
        if (s[i][j]=='T') tr=i, tc=j;
    }
    queue<tuple<int,int>> q;
    q.emplace(sr,sc);
    while (!q.empty()){
        auto [nr,nc]=q.front(); q.pop();
        if (nr<0 || nc<0 || nr>=r || nc>=c || s[nr][nc]=='#' || f1[nr][nc]) continue;
        f1[nr][nc]=1;
        if (s[nr][nc]=='+' || s[nr][nc]=='S' || s[nr][nc]=='T'){
            for (int i=0;i<4;i++) q.emplace(nr+d[i][0],nc+d[i][1]);
        }
        if (s[nr][nc]=='-'){
            for (int i=0;i<2;i++) q.emplace(nr+d[i][0], nc+d[i][1]);
        }
        if (s[nr][nc]=='|'){
            for (int i=2;i<4;i++) q.emplace(nr+d[i][0], nc+d[i][1]);
        }
        if (s[nr][nc]=='.') q.emplace(nr+1, nc);
    }
    if (!f1[tr][tc]){
        cout << "I'm stuck!";
        return 0;
    }
    int cnt=0;
    for (int i=0;i<r;i++) for (int j=0;j<c;j++){
        if (!f1[i][j]) continue;
        for (int i=0;i<r;i++) for (int j=0;j<c;j++) f2[i][j]=0;
        q.emplace(i,j);
        while (!q.empty()){
            auto [nr,nc]=q.front(); q.pop();
            if (nr<0 || nc<0 || nr>=r || nc>=c || s[nr][nc]=='#' || f2[nr][nc]) continue;
            f2[nr][nc]=1;
            if (s[nr][nc]=='+' || s[nr][nc]=='S' || s[nr][nc]=='T'){
                for (int i=0;i<4;i++) q.emplace(nr+d[i][0],nc+d[i][1]);
            }
            if (s[nr][nc]=='-'){
                for (int i=0;i<2;i++) q.emplace(nr+d[i][0], nc+d[i][1]);
            }
            if (s[nr][nc]=='|'){
                for (int i=2;i<4;i++) q.emplace(nr+d[i][0], nc+d[i][1]);
            }
            if (s[nr][nc]=='.') q.emplace(nr+1, nc);
        }
        if (!f2[tr][tc]) cnt++;
    }
    cout << cnt;
}