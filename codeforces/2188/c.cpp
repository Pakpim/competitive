#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=2e5+5;
int a[N];

signed main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        for (int i=1;i<=n;i++) cin >> a[i];
        bool f=1;
        for (int i=2;i<=n;i++){
            f &= (a[i-1]<=a[i]);
        }
        if (f){
            cout << "-1\n";
            continue;
        }
        int l=1, r=1e9, mid, ans=1, mn=1e9+5, mx=0;
        for (int i=1;i<=n;i++) mn=min(mn,a[i]), mx=max(mx,a[i]);
        while (l<=r){
            mid = l+(r-l)/2;
            bool ok=1;
            vector<int> v, s;
            for (int i=1;i<=n;i++){
                if (a[i]-mn>=mid || mx-a[i]>=mid) s.emplace_back(a[i]);
            }
            sort(s.begin(),s.end());
            int p=0;
            for (int i=1;i<=n;i++){
                if (a[i]-mn>=mid || mx-a[i]>=mid) v.emplace_back(s[p++]);
                else v.emplace_back(a[i]);
            }
            // cout << " ? " << mid << " : ";
            // for (auto e:v) cout << e << ' ';
            // cout << '\n';
            for (int i=1;i<v.size();i++){
                ok&=(v[i-1]<=v[i]);
            }
            if (ok){
                ans=max(ans,mid);
                l=mid+1;
            }
            else r=mid-1;
        }
        cout << ans << '\n';
    }
}