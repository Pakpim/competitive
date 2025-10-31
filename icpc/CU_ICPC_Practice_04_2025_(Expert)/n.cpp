#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=5e5+5;
bool f[N];
vector<int> v[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        string s;
        int k,n;
        cin >> s >> k;
        n=s.size();
        for (int i=0;i<n;i++) f[i]=1,v[i].clear(),v[i].emplace_back(i);
        deque<int> dq;
        for (int i=0;i<n;i++){
            while (!dq.empty() && k>=v[dq.back()].size() && s[dq.back()]>s[i] && (s[i]!='0' || dq.size()>1)){
                auto ni=dq.back();
                dq.pop_back();
                k-=v[ni].size();
                for (auto e:v[ni]) f[e]=0;
            }
            if (s[i]!='0') {
                dq.emplace_back(i);
            }
            else{
                v[dq.back()].emplace_back(i);
            }
        }
        while (k && !dq.empty()){
            auto ni=dq.back();
            k--;
            f[v[ni].back()]=0;
            v[ni].pop_back();
            if (v[ni].empty()) dq.pop_back();
        }
        for (int i=0;i<n;i++) if (f[i]) cout << s[i];
        cout << '\n';
    }
}