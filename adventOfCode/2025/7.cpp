#include <bits/stdc++.h>
using namespace std;

using ll=long long;
string a[500];

int main (){
    ifstream fin;
    fin.open("7.txt");
    string s;
    ll idx=1, n, m;
    while (fin >> s){
        a[idx++]='.'+s+'.';
    }
    n=idx-1;
    m=a[1].size()-2;
    for (int i=0;i<=m+1;i++) a[0]=a[0]+'.';
    for (int i=0;i<=m+1;i++) a[n+1]=a[n+1]+'.';
    int cnt=0;
    set<int> v[n+5];
    for (int i=1;i<=m;i++) if (a[1][i]=='S') v[1].emplace(i);
    for (int i=2;i<=n;i++){
        cout << i-1 << " : ";
        for (auto e:v[i-1]) cout << e << ' ';
        cout << '\n';
        for (int j=1;j<=m;j++){
            if (a[i][j]=='.') continue;
            if (v[i-1].count(j)){
                cnt++;
                v[i].emplace(j-1);
                v[i].emplace(j+1);
                v[i-1].erase(j);
            }
        }
        for (auto e:v[i-1]) v[i].emplace(e);
    }
    cout << cnt;
}