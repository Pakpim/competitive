#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using db=double;
using pll=pair<ll,ll>;
const ll N=2e5+5;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    vector<ll> v(5);
    vector<pair<ll,string>> ans;
    for (auto &e:v) cin >> e;
    for (int i=1;i<32;i++){
        string n="";
        ll sum=0;
        for (int j=0;j<5;j++){
            if (i&1<<j){
                sum+=v[j];
                n+='A'+j;
            }
        }
        ans.emplace_back(sum,n);
    }
    sort(ans.begin(),ans.end(),[](pair<ll,string> a,pair<ll,string> b){
        return (a.first>b.first) || (a.first==b.first && a.second<b.second);
    });
    for (auto [sum,n]:ans) cout << n << '\n';
}