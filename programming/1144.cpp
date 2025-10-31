#include <bits/stdc++.h>
using namespace std;

const int N=1005,K=15;
int a[N][K],b[N][K],c[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i=0;i<n;i++){
        for (int j=0;j<k;j++) cin >> a[i][j];
        for (int j=0;j<k;j++) cin >> b[i][j];
        for (int j=0;j<k;j++) if (a[i][j]>b[i][j]) swap(a[i][j],b[i][j]);
    }
    for (int i=0;i<m;i++){
        deque<int> dq[2];
        for (int i=0;i<n;i++) dq[1].emplace_back(i);
        for (int j=0;j<k;j++){
            bool ni=j&1;
            bool bi=!ni;
            dq[ni].clear();
            int x;
            cin >> x;
            for (auto e:dq[bi]){
                if (a[e][j]<=x && b[e][j]>=x) dq[ni].emplace_back(e);
            }
        }
        for (auto e:dq[(k-1)&1]) c[e]++;
    }
    vector<int> v;
    int mx=0;
    for (int i=0;i<n;i++){
        if (mx<c[i]){
            v.clear();
            mx=c[i];
        }
        if (mx==c[i]) v.emplace_back(i+1);
    }
    cout << v.size() << '\n';
    for (auto e:v) cout << e << ' ';
}