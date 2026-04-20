#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=1e3+5;
ll a[N], b[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i=1;i<n;i++) cin >> b[i];
    for (int i=1;i<=n;i++){
        vector<bool> f(n+1,0);
        bool ok=1;
        f[i]=1;
        a[1]=i;
        for (int j=1;j<n;j++){
            a[j+1]=b[j]-a[j];
            if (a[j+1]>n || a[j+1]<1 || f[a[j+1]]){
                ok=0;
                break;
            }
            f[a[j+1]]=1;
        }
        // cout << '\n';
        if (!ok) continue;
        for (int i=1;i<=n;i++) cout << a[i] << ' ';
        break;
    }
}