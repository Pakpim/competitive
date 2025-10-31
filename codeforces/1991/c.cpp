#include <bits/stdc++.h>
using namespace std;

const int N=200005;
int a[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n,mx=0,mn=2e9;
        bool ok=1;
        vector<int> v;
        cin >> n;
        for (int i=0;i<n;i++) cin >> a[i];
        for (int k=0;k<39;k++){
            mx=0,mn=2e9;
            for (int i=0;i<n;i++) mx=max(mx,a[i]),mn=min(mn,a[i]);
            if (mx==mn) break;
            if (mx==mn+1){
                ok=0;
                break;
            }
            int nv=(mx+mn)/2;
            v.emplace_back(nv);
            for (int i=0;i<n;i++){
                a[i]=abs(a[i]-nv);
            }
        }
        for (int i=1;i<n;i++){
            if (a[0]!=a[i]) ok=0;
        }
        if (!ok){
            cout << "-1\n";
            continue;
        }
        if (a[0]!=0) v.emplace_back(a[0]);
        cout << v.size() << '\n';
        for (auto e:v) cout << e << ' ';
        cout << '\n';
        // cout << " => ";
        // for (int i=0;i<n;i++) cout << a[i] << ' ';
        // cout << '\n';
    }
}