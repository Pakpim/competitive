#include <bits/stdc++.h>
using namespace std;

const int N=1005;
int a[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i=0;i<m;i++){
        cin >> a[i];
    }
    int nn,ans=0;
    cin >> nn;
    for (int i=0;i<m;i++){
        if (__builtin_popcount(nn^a[i])<=k) ans++;
    }
    cout << ans;

}