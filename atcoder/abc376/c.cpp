#include <bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int a[N],b[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n-1;i++) cin >> b[i];
    sort(a,a+n);
    sort(b,b+n-1);
    int p=n-2,cnt=0,ans=0;
    for (int i=n-1;i>=0;i--){
        // cout << " => " << a[i] << ' ' << b[p] << ' ' << cnt << '\n';
        if (p>=0 && b[p]>=a[i]) p--;
        else {
            cnt++;
            if (cnt==1) ans=a[i];
        }
    }
    if (cnt==1) cout << ans;
    else cout << -1;
}