#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int ra[N],rb[N],ca[N],cb[N],sum,ans;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            int v;
            cin >> v;
            ra[i]+=v;
            ca[j]+=v;
            sum+=v;
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            int v;
            cin >> v;
            rb[i]+=v;
            cb[j]+=v;
        }
    }
    for (int i=1;i<=n;i++){
        ans=max(ans,sum-ra[i]+rb[i-1]+rb[i+1]);
    }
    for (int i=1;i<=m;i++){
        ans=max(ans,sum-ca[i]+cb[i-1]+cb[i+1]);
    }
    cout << ans;
}