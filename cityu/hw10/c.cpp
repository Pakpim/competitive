#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int a[N];

signed main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,l;
    cin >> n >> l;
    for (int i=1;i<=n;i++) cin >> a[i];
    deque<int> dl,dr;
    for (int i=1;i<=n;i++){
        int d;
        cin >> d;
        if (d) dr.emplace_back(l-a[i]);
        else dl.emplace_back(a[i]);
    }
    for (auto e:dl) cout << e << ' ';
    // cout << '\n';
    for (auto e:dr) cout << e << ' ';
}