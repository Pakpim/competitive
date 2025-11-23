#include <bits/stdc++.h>
using namespace std;

const int N=(1<<20) + 5, R=25, M=1e9+7;
int dp[N][2], d[4][2]={{0,1},{0,-1},{1,0},{-1,0}}, a[N], cell[R][R], sum[N], sos[N][2], lg[N], mnl[R], mxl[R]; 
string s[R];
vector<pair<int,int>> g[R][R];
vector<int> ad[R], rm[R];
bool vis[R][R];

signed main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int r,c;
    cin >> r >> c;
    string _;
    getline(cin, _);
    for (int i=0;i<r+1;i++){
        getline(cin, s[i]);
    }
    for (int i=1;i<=r;i++) cin >> a[i];
    for (int i=1;i<=r;i++){
        for (int j=1,jj=1; j<=c; j++,jj+=2){
            if (s[i][jj]!='_') {
                g[i][j].emplace_back(i+1,j);
                g[i+1][j].emplace_back(i,j);
            }
            if (s[i][jj+1]!='|'){
                g[i][j].emplace_back(i,j+1);
                g[i][j+1].emplace_back(i,j);
            }
        }
    }
    int cnt=0;
    for (int i=1;i<=r;i++){
        for (int j=1;j<=c;j++){
            if (vis[i][j]) continue;
            queue<pair<int,int>> q;
            q.emplace(i,j);
            mnl[cnt]=1e9;
            while (!q.empty()){
                auto [nr,nc]=q.front();
                q.pop();
                if (vis[nr][nc]) continue;
                vis[nr][nc]=1;
                cell[cnt][nr]++;
                mnl[cnt]=min(mnl[cnt],nr);
                mxl[cnt]=max(mxl[cnt],nr);
                for (auto [xr,xc]:g[nr][nc]){
                    q.emplace(xr,xc);
                }
            }
            cnt++;
        }
    }
    for (int i=0;i<cnt;i++){
        ad[mxl[i]].emplace_back(i);
        rm[mnl[i]-1].emplace_back(i);
    }
    for (int i=0;i<cnt;i++){
        lg[1<<i]=i;
    }
    dp[(1<<cnt)-1][(r+1)&1]= 1;
    int b1=(1<<cnt)-1, b2=0;
    for (int i=r;i>0;i--){
        for (int j=1;j<1<<cnt;j++){
            sum[j]=(sum[j-(j&-j)]+cell[lg[j&-j]][i])%M;
        }
        int ni=i&1, bi=ni^1;
        for (int j=0;j<1<<cnt;j++) dp[j][ni]=0;
        for (auto e:ad[i]){
            b2^=1<<e;
            b1^=1<<e;
        }
        for (auto e:rm[i]){
            b2^=1<<e;
        }
        for (int j=0;j<(1<<cnt);j++) {
            sos[j][0]=dp[j][bi];
        }
        for (int k=0, bk=0, nk=1;k<cnt;k++, bk^=1, nk^=1){
            for (int j=(1<<cnt)-1;j>=0;j--){
                sos[j][nk]=sos[j][bk];
                if ((j>>k&1)==0) sos[j][nk]+=sos[j^(1<<k)][bk];
                sos[j][nk]%=M;
            }
        }
        for (int j=b2;j>=0;j=(j-1)&b2){
            int nb=j|b1;
            if (a[i]!=-1 && sum[nb]!=a[i]) {
                if (j<=0) break;
                continue;
            }
            dp[nb][ni]=sos[nb][cnt&1];
            // cout << i << " " << bitset<5>(b1) << ' ' << bitset<5>(b2) << " => " << ' ' << bitset<5>(nb) << ' ' << dp[nb][i] << '\n';
            if (j<=0) break;
        }
    }
    int ans=0;
    for (int i=0;i<1<<cnt;i++){
        ans+=dp[i][1];
        ans%=M;
    }
    cout << ans << '\n';
}

/*
6 7
 _ _ _ _ _ _ _ 
| |  _ _|  _  |
| | |_ _| |_| |
| |_ _ _|  _ _|
| |  _ _| |   |
| | |_ _| |   |
|_|_ _ _|_|_ _|
6 3 7 2 2 2

*/