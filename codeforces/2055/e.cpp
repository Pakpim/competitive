#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=5e5+5;
pair<ll,ll> a[N];
ll s1[N],s2[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    vector<pair<ll,ll>> v1,v2;
    while (t--){
        int n;
        cin >> n;
        for (int i=0;i<n;i++){
            int a,b;
            cin >> a >> b;
            if (a<=b) v1.emplace_back(a,b);
            else v2.emplace_back(-b,a);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        vector<pair<int,int>> v;
        for (auto [a,b]:v1) v.emplace_back(a,b);
        for (auto [b,a]:v2) v.emplace_back(a,-b);

    }
}

