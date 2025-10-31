#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=2e5+5;
ll a[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        for (int i=1;i<=n;i++) cin >> a[i];
        vector<int> c(3,0);
        for (int i=1;i<=n;i++) c[a[i]]++;
        set<int> s[3];
        for (int i=1;i<=n;i++){
            s[a[i]].emplace(i);
        }
        vector<pair<int,int>> ans;
        while ((!s[0].empty() &&  *(prev(s[0].end()))>*s[1].begin()) || (!s[2].empty() && *(prev(s[1].end()))>*s[2].begin())){
            if (!(!s[0].empty() &&  *(prev(s[0].end()))>*s[1].begin())){
                auto it0=s[1].end(); it0--;
                int p0=*it0;
                s[1].erase(it0);
                auto it1=s[2].begin();
                int p1=*it1;
                s[2].erase(it1);
                s[1].emplace(p1);
                s[2].emplace(p0);
                ans.emplace_back(p0,p1);
                swap(a[p0],a[p1]);
            }
            else if (!(!s[2].empty() && *(prev(s[1].end()))>*s[2].begin())){
                auto it0=s[0].end(); it0--;
                int p0=*it0;
                s[0].erase(it0);
                auto it1=s[1].begin();
                int p1=*it1;
                s[1].erase(it1);
                s[0].emplace(p1);
                s[1].emplace(p0);
                ans.emplace_back(p0,p1);
                swap(a[p0],a[p1]);
            }
            else{
                auto it0=s[1].end(); it0--;
                int p0=*it0;
                s[1].erase(it0);
                auto it1=s[2].begin();
                int p1=*it1;
                s[2].erase(it1);
                s[1].emplace(p1);
                s[2].emplace(p0);
                ans.emplace_back(p0,p1);
                swap(a[p0],a[p1]);
                 it0=s[0].end(); it0--;
                 p0=*it0;
                s[0].erase(it0);
                 it1=s[1].begin();
                 p1=*it1;
                s[1].erase(it1);
                s[0].emplace(p1);
                s[1].emplace(p0);
                ans.emplace_back(p0,p1);
                swap(a[p0],a[p1]);
            }
        }
        // for (int i=1;i<=n;i++) cout << a[i] << ' ';
        // cout << '\n';
        cout << ans.size() << '\n';
        for (auto [x,y]:ans) cout << x << ' ' << y << '\n';
    }
}

/*
3
4
0 2 0 1
3
1 2 0
6
0 1 1 2 2 2
3
2 1 0
*/