#include <bits/stdc++.h>
using namespace std;

const int N=1e5*5;
bool f[N];
vector<int> p;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    for (int i=2;i<N;i++){
        if (f[i]) continue;
        p.emplace_back(i);
        for (int j=i*2;j<N;j+=i) f[j]=1;
    }
    int n;
    while (cin >> n){
        if (n==0) return 0;
        cout << n << " = ";
        vector<int> ans;
        if (n<0) ans.emplace_back(-1), n*=-1;
        for (auto e:p){
            if (n<N && !f[n]) {
                break;
            }
            while (n%e==0){
                ans.emplace_back(e);
                n/=e;
            }
        }
        if (n!=1) ans.emplace_back(n);

        for (int i=0;i<ans.size();i++){
            cout << ans[i];
            if (i<ans.size()-1) cout << " x ";
        }
        cout << '\n';
    }
}