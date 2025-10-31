#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,c,ans=1;
    cin >> n >> c;
    vector<int> t(n);
    for (auto &e:t) cin >> e;
    int tmp=t[0];
    for (int i=1;i<n;i++){
        if (t[i]-tmp>=c) {
            ans++;
            tmp=t[i];
        }
    }
    cout << ans;
}