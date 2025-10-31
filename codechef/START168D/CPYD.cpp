#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int cnt[N],mn[N],mx[N],a[N],b[N];
bool f[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n,ans=0;
        cin >> n;
        for(int i=1;i<=n;i++) cin >> a[i];
        for (int i=0;i<=n;i++){
            cnt[i]=0;
            mn[i]=1e9;
            mx[i]=-1;
            b[i]=0;
            f[i]=0;
        }
        for (int i=1;i<=n;i++){
            cnt[a[i]]++;
            mn[a[i]]=min(mn[a[i]],i);
            mx[a[i]]=max(mx[a[i]],i);
        }
        for (int i=1;i<=n;i++){
            if (cnt[a[i]]==1) f[i]=1;
            if (cnt[i]<2) continue;
            ans++;
            b[mn[i]]+=1;
            b[mx[i]+1]-=1;
        }
        for (int i=1;i<=n;i++){
            b[i]+=b[i-1];
            if (b[i]&&f[i]) ans++;
        }
        cout << ans << '\n';
    }
}