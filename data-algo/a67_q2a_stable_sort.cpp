#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=1e5+5;
ll a[N],b[N];
map<int,vector<int>> mp;
deque<int> v[N],v2[N];
set<int> s[N];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        mp[a[i]].emplace_back(i);
    }
    int tmp=1;
    for (auto [k,val]:mp){
        for (auto e:val){
            v[tmp].emplace_back(e);
        }
        tmp++;
    }
    int np=1;
    for (int i=1;i<=n;i++){
        int xp=np+v[i].size();
        while (!v[i].empty()){
            v2[np].emplace_back(v[i].front());
            s[np].emplace(v[i].front());
            v[i].pop_front();
        }
        np=xp;
    }
    while (m--){
        bool a1=1,a2=1;
        int np=1,p2=0;
        for (int i=1;i<=n;i++){
            cin >> b[i];
            while (np+v2[np].size()-1<i) np++,p2=0;
            if (!s[np].count(b[i])){
                a1=0;
                a2=0;
            }
            if (v2[np][p2]!=b[i]) a2=0;
            p2++;
        }
        cout << a1 << ' ' << a2 << '\n';
    }
}