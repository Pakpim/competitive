#include <bits/stdc++.h>
using namespace std;

using ll=long long;

void dfs (vector<int> v,int n){
    if (v.size()==n){
        for (auto e:v) cout << e << ' ';
        cout << '\n';
        // exit(0);
        return;
    }
    vector<bool> f(n,0);
    for (auto e:v) f[e]=1;
    for (int i=1;i<=n;i++){
        if (f[i]) continue;
        bool ok=1;
        int sum=0;
        for (int j=v.size()-1;j>=0;j--){
            sum+=v[j];
            if ((sum+i)%(n+1)==0) ok=0;
        }
        if (ok){
            vector<int> vx=v;
            vx.emplace_back(i);
            dfs(vx,n);
        }
    }
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        // n=t*2+1;
        cin >> n;
        // cout << '\n' << n << " : ";
        if (!(n&1)){
            cout << "-1\n";
            continue;
        }
        // dfs({},n);
        // wtf
        for (int i=1;i<=n;i++){
            if (i&1) cout << i << ' ';
            else cout << n-i+1 << ' ';
        }
        cout << '\n';
    }
}