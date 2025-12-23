#include <bits/stdc++.h>
using namespace std;

using ll=long long;

signed main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while (t--){
        ll n;
        cin >> n;
        vector<tuple<ll,ll,ll>> v(n);
        ll ans=0, sum=0;
        vector<ll>mx(8,-1e18);
        for (auto &[x,y,c]:v) cin >> x;
        for (auto &[x,y,c]:v) cin >> y;
        for (auto &[x,y,c]:v) cin >> c;
        if (n<5){
            ll ans=0;
            for (int i=1;i<1<<n;i++){
                ll nv=0, x1=1e18, x2=-1e18, y1=1e18, y2=-1e18;
                for (int j=0;j<n;j++){
                    auto [x,y,c]=v[j];
                    if (i>>j&1){
                        x1=min(x1,x);
                        x2=max(x2,x);
                        y1=min(y1,y);
                        y2=max(y2,y);
                    }
                    else{
                        nv+=c;
                    }
                }
                nv+=(x2-x1+y2-y1)*2;
                ans=max(ans,nv);
            }
            cout << ans << '\n';
            continue;
        }
        for (auto [x,y,c]:v){
            mx[0]=max(mx[0], x*2-c);
            mx[1]=max(mx[1], y*2-c);
            mx[2]=max(mx[2],-x*2-c);
            mx[3]=max(mx[3],-y*2-c);
            mx[4]=max(mx[4], x*2+y*2-c);
            mx[5]=max(mx[5],-x*2+y*2-c);
            mx[6]=max(mx[6], x*2-y*2-c);
            mx[7]=max(mx[7],-x*2-y*2-c);
            sum+=c;
        }
        mx[4]=max(mx[4], mx[0]+mx[1]);
        mx[5]=max(mx[5], mx[2]+mx[1]);
        mx[6]=max(mx[6], mx[0]+mx[3]);
        mx[7]=max(mx[7], mx[2]+mx[3]);
        ans=max({ans,sum+ mx[4]+mx[7],sum+ mx[5]+mx[6]});
        cout << ans << '\n';
    }
}