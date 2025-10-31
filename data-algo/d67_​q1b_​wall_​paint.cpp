#include <bits/stdc++.h>
using namespace std;

const int N=1e6+5,M=3e5+5;
int pos[M][2],ar[N];

set<pair<int,int>> s;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i=0;i<m*2;i++){
        int x,c,d;
        cin >> x >> c >> d;
        pos[c][d]=x;
    }
    s.emplace(pos[1][0],pos[1][1]);
    s.emplace(pos[1][1],1e9);
    for (int i=2;i<=m;i++){
        //cout << " => " << pos[i][0] << ' ' << pos[i][1] << '\n';
        auto it = s.lower_bound(make_pair(pos[i][0],-1));
        auto it2 = s.lower_bound(make_pair(pos[i][1],-1));
        if (it->first == pos[i][0] || it2->first==pos[i][1] || it!=it2){
            continue;
        }
        s.emplace(pos[i][0],pos[i][1]);
        s.emplace(pos[i][1],1e9);
    }
    for (auto [a,b]:s){
        if (b==1e9) continue;
        // cout << " --> " << a << ' ' << b << '\n';
        ar[a]++;
        ar[b+1]--;
    }
    int mx=0;
    for (int i=1;i<=n;i++){
        ar[i]+=ar[i-1];
        mx=max(mx,ar[i]);
    }
    cout << mx;
}