#include <bits/stdc++.h>
using namespace std;

bool p[100005];
vector <int> f;
set <tuple<int,int,int>> ans;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int a,b,c;
    cin >> a >> b;
    c=__gcd(a,b);
    for (int i=2;i<100000;i++){
        if (p[i]) continue;
        for (int j=i;j<100000;j+=i) p[j]=1;
        while (c%i==0) {
            f.emplace_back(i);
            c/=i;
        }
    }
    if (c!=1) f.emplace_back(c);
    int sz=f.size();
    for (int i=0;i<1<<sz;i++){
        int n=1;
        for (int j=0;j<sz;j++) if (i&1<<j) n*=f[j];
        ans.emplace(n,a/n,b/n);
    }
    for (auto [n,x,y]:ans) cout << n << ' ' << x << ' ' << y << '\n';
}