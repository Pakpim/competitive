#include <bits/stdc++.h>
using namespace std;

bool f[200005];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,a,cnt=0;
    cin >> n >> a;
    f[a]=1;
    for (int i=0;i<n;i++){
        if (i) f[i]|=f[(i-1)/2];
        if (f[i]) cnt++;
    }
    cout << cnt << '\n';
    for (int i=0;i<n;i++) if (f[i]) cout << i << ' ';
}