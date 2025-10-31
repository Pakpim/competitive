#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=200005;
int a[N],b[N],pa[N],pb[N],sa[N],sb[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n,ans=0,cnt=0;
        cin >> n;
        for (int i=1;i<=n;i++) cin >> a[i];
        for (int i=1;i<=n;i++) cin >> b[i];
        pa[0]=a[1]; pb[0]=b[1]; sa[n+1]=a[n]; sb[n+1]=b[n];
        for (int i=1;i<=n;i++) pa[i]=__gcd(a[i],pa[i-1]), pb[i]=__gcd(b[i],pb[i-1]);
        for (int i=n;i>=1;i--) sa[i]=__gcd(a[i],sa[i+1]), sb[i]=__gcd(b[i],sb[i+1]);
        ans=pa[n]+pb[n];
        cnt=1;
        for (int i=1;i<n;i++) {
            int nv=__gcd(pa[i],sb[i+1])+__gcd(pb[i],sa[i+1]);
            if (nv>ans){
                ans=nv;
                cnt=0;
            }
            if (nv==ans) cnt+=2;
        }
        for (int i=2;i<=n+1;i++) {
            if (pa[i]!=pa[i-1] || pb[i]!=pb[i-1]){
                int ga=pa[i-1],gb=pb[i-1];
                for (int j=i;j<n;j++){
                    ga=__gcd(ga,b[j]);
                    gb=__gcd(gb,a[j]);
                    int nv=__gcd(ga,sa[j+1])+__gcd(gb,sb[j+1]);
                    if (nv>ans){
                        ans=nv;
                        cnt=0;
                    }
                    if (nv==ans) {
                        cnt++;
                        
                    }
                    cout << i << ' ' << j << ' ' << nv << " => " << ans << ' ' << cnt << '\n';
                }

            }
        }
        cout << ans << ' ' << cnt << '\n';
    }
}

/*
1
2
18 13
15 20
*/