#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N=105;
int a[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    pair<int,int> mx={-1,0}, mn={1e9,0};
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> a[i];
        mx=max(mx,{a[i],-i});
        mn=min(mn,{a[i],-i});
    }
    int pf=-mx.second,pb=-mn.second;
    if (pf<pb) cout << pf+n-1-pb;
    else cout << pf+n-1-pb-1;
}