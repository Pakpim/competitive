#include <bits/stdc++.h>
using namespace std;

const int N=105;
int n,m,k,ans=1e9,qs[N],v[N];
bool f[N];

int min(int cnt){
    int re=0;
    for (int i=0;i<n;i++){
        if (cnt==0) break;
        if (f[i]) continue;
        cnt--;
        re+=v[i];
    }
    return re;
}

int mx (int cnt){
    int re=0;
    for (int i=n-1;i>=0;i--){
        if (cnt==0) break;
        if (f[i]) continue;
        cnt--;
        re+=v[i];
    }
    return re;
}

void dfs (int nn,int sum,int cnt){
    // cout << nn << " => " << sum << ' ' << cnt << '\n';
    if (cnt==0) ans=min(ans,abs(k-sum));
    if (nn==n) return;
    if (cnt<=0) return;
    if (sum>k && sum-k>=ans) return;
    if (n-nn+1<cnt) return;
    if (n-nn+1==cnt){
        ans=min(ans,abs(sum+qs[nn]-k));
        return;
    }
    if (sum>=k){
        ans=min(ans,sum+min(cnt)-k);
        return;
    }
    int tmp=mx(cnt);
    if (sum+tmp<k) {
        ans=min(ans,k-(sum+tmp));
        return;
    }
    dfs(nn+1,sum,cnt);
    f[nn]=1;
    dfs(nn+1,sum+v[nn],cnt-1);
    f[nn]=0;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    for (int i=0;i<n;i++) cin >> v[i];
    sort(v,v+n);
    for (int i=n;i>=0;i--) qs[i]=qs[i+1]+v[i];
    ans=abs(k-qs[n-m+1]);
    dfs(0,0,m);
    cout << ans;
}