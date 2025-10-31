#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=2e5+5;
ll a[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        ll n,m,ans=0;
        cin >> n >> m;
        for (int i=0;i<m;i++) cin >> a[i];
        sort(a,a+m);
        int p=m-1;
        ll cnt=0,cnt2=0,sum=0;
        while (p>=0 && a[p]>=n){
            cnt2++;
            p--;
        }
        if (p<0){
            cout << m*(m-1)*(n-1) << '\n';
            continue;
        }
        cnt=1; sum=a[p];
        for (int i=0;i<m-cnt2;i++){
            ll nv = 0;
            nv += a[i]*cnt2;
            if (a[i]+a[p] >= n){
                while (p>0 && a[p-1]+a[i]>=n){
                    p--;
                    cnt++;
                    sum+=a[p];
                }
                if (p<=i){
                    nv+=(a[i]-n+1ll)*(cnt-1ll) + (sum-a[i]);
                }
                else{
                    nv+=(a[i]-n+1ll)*cnt + sum;
                }

            }
            // cout << i << ' ' << p << ' ' << a[i] << ' ' << a[p]  << " = " << nv << ' ' << sum << ' ' << cnt << ' ' << cnt2 << '\n';
            ans+=nv;
        }
        while (p>0) sum+=a[--p]; 
        ans+=cnt2*(cnt2-1)*(n-1) + cnt2*sum;
        cout << ans << '\n';
    } 
}