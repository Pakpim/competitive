#include <bits/stdc++.h>
using namespace std;

const int N=300005;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n,k;
        cin >> n >> k;
        vector<pair<int,int>> v;
        for (int i=1;i<=n;i++){
            int h;
            cin >> h;
            h%=k;
            if (h==0) h+=k;
            v.emplace_back(-h,i);
        }
        sort(v.begin(),v.end());
        for (auto [a,b]:v) cout << b << ' ';
        cout << '\n';
    }
}