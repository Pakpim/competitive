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
        int n,cnt=0;
        cin >> n;
        for (int i=0;i<=n;i++) a[i]=0;
        for (int i=0;i<n;i++){
            int v;
            cin >> v;
            a[v]++;
        }
        for (int i=1;i<=n;i++){
            if (!a[i]) continue;
            a[0]+=a[i]/2;
            cnt+=a[i]%2;
        }
        if (a[0]) cnt++;
        cout << cnt << '\n';
    }
}