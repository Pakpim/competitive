#include <bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int a[N],b[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n,mn=1e9,cnt=0,sum=0;
        cin >> n;
        for (int i=1;i<=n;i++) cin >> a[i];
        for (int i=1;i<=n;i++) cin >> b[i];
        for (int i=1;i<=n;i++){
            if (b[i]<=a[i]) mn=min(mn,a[i]-b[i]);
            else sum+=b[i]-a[i],cnt++;
        }
        if (mn>=sum && cnt<2) cout << "YES\n";
        else cout << "NO\n";
    }
}