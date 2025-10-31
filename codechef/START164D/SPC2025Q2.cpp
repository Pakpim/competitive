#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n,k,p;
        cin >> n >> k >> p;
        vector<int> v(n);
        for (auto &e:v) cin >>e;
        sort(v.begin(),v.end() );
        int s0=p,s1=k;
        for (int i=0;i<n-1;i++) s0+=v[i];
        s1+=v[n-1];
        // cout << " => " << s0 << ' ' << s1 << '\n';
        if (s0==s1) cout << "Equal\n";
        else if (s0>s1) cout << "Varun\n";
        else cout << "Ved\n";
    }
}