#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=2e5+5;
int a[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n,mx,ans=0;
        cin >> n;
        for (int i=1;i<=n;i++){
            cin >> a[i];
        }
        for (int i=1;i<=n;i++){
            int tl=0,tr=0;
            if (i==2) tl=a[1];
            if (i==n-1) tr=a[n];
            ans=max(ans,a[i]-tl-tr);
        }
        cout << ans << '\n';
    }
}