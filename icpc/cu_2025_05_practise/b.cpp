#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=1e4+5;
int dis[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i=0;i<N;i++) dis[i]=1e9;
    queue<pair<int,int>> q;
    q.emplace(n,0);
    while (!q.empty()){
        auto [nn,nd]=q.front();
        q.pop();
        if (nn==m){
            cout << nd;
            return 0;
        }
        if (dis[nn]<=nd) continue;
        dis[nn]=nd;
        if (nn*2<N && dis[nn*2]>nd+1){
            q.emplace(nn*2,nd+1);
        }
        if (nn-1>=0 && dis[nn-1]>nd+1){
            q.emplace(nn-1,nd+1);
        }
    }
}