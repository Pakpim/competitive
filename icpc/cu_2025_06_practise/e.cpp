#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=2e5+5;
ll qs[N],a[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        string s;
        cin >> n >> s;
        int cnt = 0;
        vector<int> v0,v1;
        vector<int> ans(n,0);
        for (int i=0;i<n;i++){
            auto e = s[i];
            if (e=='0'){
                if (!v1.empty()){
                    ans[i]=v1.back();
                    v1.pop_back();
                }
                else{
                    cnt++;
                    ans[i]=cnt;
                }
                v0.emplace_back(ans[i]);
            }
            else{
                if (!v0.empty()){
                    ans[i]=v0.back();
                    v0.pop_back();
                }
                else{
                    cnt++;
                    ans[i]=cnt;
                }
                v1.emplace_back(ans[i]);
            }
        }
        cout << cnt << '\n';
        for (auto e:ans) cout << e << ' ';
        cout << '\n';
    }
}