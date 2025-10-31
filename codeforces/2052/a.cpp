#include <bits/stdc++.h>
using namespace std;

const int N=1005;
int c[N],p[N],c2[N];
bool f[N][N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> c[i],p[c[i]]=i,c2[i]=c[i];
    deque<pair<int,int>> ans;
    for (int i=1;i<=n;i++){
        while (p[i]!=i){
            int a=c2[p[i]-1],b=i;
            f[a][b]=1;
            ans.emplace_front(a,b);
            swap(p[a],p[b]);
            c2[p[a]]=a;
            c2[p[b]]=b;
        }
    }
    deque<pair<int,int>> t1,t2;
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            int a=c[i],b=c[j];
            if (f[a][b] || f[b][a]) break;
            t1.emplace_back(b,a);
            t2.emplace_front(a,b);
            f[a][b]=f[b][a]=1;
        }
        while (!t1.empty()){
            auto [a,b]=t1.front(); t1.pop_front();
            ans.emplace_back(a,b);
        }
        while (!t2.empty()){
            auto [a,b]=t2.front(); t2.pop_front();
            ans.emplace_back(a,b);
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            int a=i,b=j;
            if (f[a][b] || f[b][a]) break;
            t1.emplace_back(b,a);
            t2.emplace_front(a,b);
            f[a][b]=f[b][a]=1;
        }
        while (!t2.empty()){
            auto [a,b]=t2.back(); t2.pop_back();
            ans.emplace_front(a,b);
        }
        while (!t1.empty()){
            auto [a,b]=t1.back(); t1.pop_back();
            ans.emplace_front(a,b);
        }
    }
    cout << ans.size() << '\n';
    for (auto [a,b]:ans) cout << a << ' ' << b << '\n';
}