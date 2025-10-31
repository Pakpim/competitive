#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=2505,K=20005;
bool f[N][N];
int a[N][N],dp[N][N],x[K],y[K],ans[K],tl[N],tr[N];
set<int> s[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,k,mx=0;
    cin >> n >> m >> k;
    for (int i=1;i<=k;i++){
        cin >> y[i] >> x[i];
        f[y[i]][x[i]]=1;
        s[x[i]].emplace(y[i]);
    }
    for (int i=1;i<=n;i++){
        for (int j=m;j>0;j--){
            if (f[i][j]) continue;
            a[i][j]=a[i][j+1]+1;
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (f[i][j]) continue;
            dp[i][j]=min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]})+1;
            mx=max(mx,dp[i][j]);
        }
    }
    ans[k]=mx;
    for (int i=1;i<=m;i++) s[i].emplace(0),s[i].emplace(n+1);
    for (int i=k;i>0;i--){
        f[y[i]][x[i]]=0;
        s[x[i]].erase(y[i]);
        tl[x[i]-1]=1;
        tr[x[i]-1]=n;
        int l=1,r=n,p;
        for (int j=x[i];!f[y[i]][j] && j<=m;j++){
            auto it1=s[j].upper_bound(y[i]);
            it1--;
            auto it2=s[j].lower_bound(y[i]);
            tl[j]=max(tl[j-1],*it1+1);
            tr[j]=min(tr[j-1],*it2-1);
            if (x[i]-j+1 <= tr[j]-tl[j]+1) p=j;
        }
        for (int j=x[i];j>0;j--){
            if (f[y[i]][j]) break;
            a[y[i]][j]=a[y[i]][j+1]+1;
            auto it1=s[j].upper_bound(y[i]);
            it1--;
            auto it2=s[j].lower_bound(y[i]);
            l=max(l,*it1+1);
            r=min(r,*it2-1);
            while (min(r,tr[p])-max(l,tl[p])+1<p-j+1)p--;
            int nl=max(l,tl[p]),nr=min(r,tr[p]);
            int nv=min(p-j+1,(nr-nl+1));
            mx=max(mx,nv);
            // cout << " ? " << tr[p]-tl[p]+1 << ' ' << p-j+1 << '\n';
            // cout<< ' ' << y[i] << ' ' << j << ' ' << p << " : " << nl << ' ' << nr << " = " << nv << '\n';
        }
        ans[i-1]=mx;
        // cout << '\n';
    }
    for (int i=1;i<=k;i++) cout << ans[i] << '\n';
}