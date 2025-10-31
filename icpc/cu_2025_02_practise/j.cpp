#include <bits/stdc++.h>
using namespace std;

const int N=1005;
deque<int> l[N],r[N];
vector<tuple<int,int,int>> ans;

void cal (int nl,int nr){
    if (nl>nr) return;
    r[nl].pop_back();
    l[nr].pop_front();
    if (r[nl].empty()){
        ans.emplace_back(nl,nr,nl);
        cal(nl+1,nr);
        return;
    }
    if (l[nr].empty()){
        ans.emplace_back(nl,nr,nr);
        cal(nl,nr-1);
        return;
    }
    if (nl==nr){
        ans.emplace_back(nl,nl,nl);
        return;
    }
    int m1 = r[nl].back(), m2=l[nr].front();
    ans.emplace_back(nl,nr,m1+1);
    // cout << " ? " << nl << ' ' << nr << ' ' << m1 << ' ' << m2 << '\n';
    cal(nl,m1);
    cal(m2,nr);
    return;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        for (int i=1;i<=n;i++){
            l[i].clear();
            r[i].clear();
        }
        ans.clear();
        for (int i=0;i<n;i++){
            int nl,nr;
            cin >> nl >> nr;
            r[nl].emplace_back(nr);
            l[nr].emplace_back(nl);
        }
        for (int i=1;i<=n;i++){
            sort(l[i].begin(),l[i].end());
            sort(r[i].begin(),r[i].end());
        }
        cal(1,n);
        for (auto [nl,nr,nn]:ans) cout << nl << ' ' << nr << ' ' << nn << '\n';
        cout << '\n';
    }
}