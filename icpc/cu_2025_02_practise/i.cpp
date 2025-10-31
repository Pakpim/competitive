#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=1e6;
bool f[N];
vector<ll> p;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    for (int i=2;i<N;i++){
        if (f[i]) continue;
        p.emplace_back(i);
        for (int j=i*2;j<N;j+=i) f[j]=1;
    }
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<ll> v(n);
        for (auto &e:v) cin >> e;
        sort(v.begin(),v.end());
        ll x=v[0]*v[n-1];
        bool ok=1;
        for (int i=1,j=n-2;i<=j;i++,j--){
            if (v[i]*v[j]!=x) ok=0;
        }
        ll tmp = x,sum=1;
        for (auto e:p){
            if (tmp==1) break;
            int cnt=0;
            while (tmp%e==0){
                cnt++;
                tmp/=e;
            }
            sum*=(cnt+1);
        }
        if (sum-2!=n) ok=0;
        if (!ok) x=-1;
        cout << x << '\n';
    }
}