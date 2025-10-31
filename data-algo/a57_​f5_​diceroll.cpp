#include <bits/stdc++.h>
using namespace std;

const int inf=1e9;
int r,c,tr,tc,a[5][2],d[15][15][10][50];
bool ok=1;
int ans=inf;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> r >> c >> tr >> tc;
    // u d l r f b
    for (int i=0;i<3;i++) cin >> a[i][0] >> a[i][1];
    swap(a[1][0],a[1][1]);
    for (int i=0;i<r;i++) for (int j=0;j<c;j++) for (int k=0;k<10;k++) for (int l=0;l<50;l++) d[i][j][k][l]=inf;
    priority_queue<tuple<int,int,vector<int>,vector<int>,int,int>> q;
    q.push({0,0,{0,0,0},{0,1,2},0,-a[0][0]});
    while (!q.empty()){
        auto [nr,nc,ns,nf,nn,sum]=q.top();
        q.pop();
        if (nr<0 || nc <0 || nr>=r || nc>=c || !ok) continue;
        sum+=a[nf[0]][ns[nf[0]]];
        int ni=ns[0]+(ns[1]<<1)+(ns[2]<<2),nj=nf[0]+(nf[1]<<2)+(nf[2]<<4);
        // cout << nr << ' ' << nc << ' ' << ni << ' ' << nj << " : " << ns[0] << ns[1] << ns[2] << ' ' << nf[0] << nf[1] << nf[2] << ' ' << nn << ' ' << sum << '\n';
        if (nn>r*c*36){
            if (sum<d[nr][nc][ni][nj]) ok=0;
            continue;
        }
        if (sum>=d[nr][nc][ni][nj]) continue;
        d[nr][nc][ni][nj]=sum;
        if (nr==tr && nc==tc) ans=min(ans,sum);
        swap(nf[0],nf[1]); ns[nf[1]]^=1;
        q.push({nr,nc-1,ns,nf,nn+1,sum});
        ns[nf[1]]^=1; ns[nf[0]]^=1;
        q.push({nr,nc+1,ns,nf,nn+1,sum});
        ns[nf[0]]^=1; swap(nf[0],nf[1]);
        swap(nf[0],nf[2]); ns[nf[2]]^=1;
        q.push({nr-1,nc,ns,nf,nn+1,sum});
        ns[nf[2]]^=1; ns[nf[0]]^=1;
        q.push({nr+1,nc,ns,nf,nn+1,sum});
    }
    if (ok) cout << ans;
    else cout << "-1";
}