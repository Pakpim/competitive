#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using db=double;
vector<ll> p[1005];
int par[1005];

db dist(int x,int y){
    ll sum=0;
    for (int i=0;i<3;i++) sum+=(p[x][i]-p[y][i])*(p[x][i]-p[y][i]);
    return sqrt(sum);
}

int root(int nn){
    if (par[nn] && par[nn]!=nn) return par[nn]=root(par[nn]);
    return nn;
}

int main (){
    ifstream fin;
    fin.open("8.txt");
    string s;
    ll idx=1, n;
    while (fin >> s){
        ll nv=0;
        for (auto e:s){
            if (e==',') p[idx].emplace_back(nv), nv=0;
            else nv=nv*10+e-'0';
        }
        p[idx].emplace_back(nv);
        idx++;
    }
    n=idx-1;
    cout << "? " << n << '\n';
    vector<tuple<db,ll,ll>> v;
    for (int i=2;i<=n;i++){
        for (int j=1;j<i;j++){
            v.emplace_back(dist(i,j),i,j);
        }
    }
    sort(v.begin(),v.end());
    ll ans=0;
    for (int i=1,t=1;i<=1000, t<n;i++){
        auto [nd,ni,nj]=v[i-1];
        ans=p[ni][0]*p[nj][0];
        if (root(ni)==root(nj)) continue;
        // cout << p[ni][0] << ' ' << p[ni][1] << ' ' << p[ni][2] << " <=> " << p[nj][0] << ' ' << p[nj][1] << ' ' << p[nj][2] << '\n';
        ni=root(ni); nj=root(nj);
        // cout << ni << ' ' << nj << '\n';
        par[ni]=root(nj);
        t++;
    }
    cout << ans;
    // map<ll,ll> mp;
    // for (int i=1;i<=n;i++){
    //     mp[root(i)]++;
    // }
    // vector<ll> tmp;
    // for (auto [e1,e2]:mp) tmp.emplace_back(-e2);
    // sort(tmp.begin(),tmp.end());
    // cout << tmp[0]*tmp[1]*tmp[2]*-1;
}