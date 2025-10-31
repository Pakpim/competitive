#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=205;

string g[N];
int r,c,mir;

bool cal (int sr,int sc,int sdr,int sdc){
    queue<tuple<int,int,int,int>> q;
    vector<vector<bool>> f(r+5,vector<bool>(c+5,0));
    int cnt=0;
    q.emplace(sr,sc,sdr,sdc);
    while (!q.empty()){
        auto [nr,nc,dr,dc]=q.front();
        q.pop();
        if (!nr || !nc || nr>r || nc>c) continue;
        char ch=g[nr-1][nc-1];
        if (ch!='.' && !f[nr][nc]) cnt++;
        f[nr][nc]=1;
        if (ch=='\\'){
            swap(dr,dc);
        }
        if (ch=='/'){
            swap(dr,dc);
            dr=-dr;
            dc=-dc;
        }
        q.emplace(nr+dr,nc+dc,dr,dc);
    }
    return mir==cnt;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> r >> c;
    vector<tuple<char,int>> ans;
    for (int i=0;i<r;i++) cin >> g[i];
    for (int i=0;i<r;i++) for (int j=0;j<c;j++) mir+=(g[i][j]!='.');
    for (int i=1;i<=r;i++){
        if (cal(i,1,0,1)) ans.emplace_back('W',i);
        if (cal(i,c,0,-1)) ans.emplace_back('E',i);
    }
    for (int i=1;i<=c;i++){
        if (cal(1,i,1,0)) ans.emplace_back('N',i);
        if (cal(r,i,-1,0)) ans.emplace_back('S',i);
    }
    cout << ans.size() << '\n';
    for (auto [a,b]:ans) cout << a << b << ' ';
}