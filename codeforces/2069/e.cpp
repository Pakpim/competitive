#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=5e5+5;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        string s;
        int n[4];
        cin >> s >> n[0] >> n[1] >> n[2] >> n[3];
        s+=s[s.size()-1];
        char bf='C';
        int cnt=0,sum=0;
        priority_queue<int,vector<int>,greater<int>> pq[2];
        for (auto e:s){
            if (e==bf){
                // cout << " => " << e << ' ' << cnt << '\n';
                if (cnt&1){
                    n[e-'A']--;
                    sum+=(cnt-1)/2;
                }
                else{
                    pq[(e-'A')^1].emplace(cnt);
                }
                cnt=0;
            }
            bf=e;
            cnt++;
        }
        for (int k=0;k<2;k++){
            while (!pq[k].empty()){
                int nv=pq[k].top();
                if (nv/2>n[k+2]) break;
                pq[k].pop();
                n[k+2]-=nv/2;
            }
        }
        // cout << " ?? " << pq[0].size() << ' ' << pq[1].size() << '\n';
        for (int k=0;k<2;k++){
            while (!pq[k].empty()){
                int nv=pq[k].top();
                pq[k].pop();
                sum+=(nv-2)/2;
                n[0]--;
                n[1]--;
            }
        }
        // cout << " ? " << n[0] << ' ' << n[1] << ' ' << n[2] << ' ' <<  n[3] << '\n';
        if (n[0]<0 || n[1]<0 || n[2]+n[3]+min(n[0],n[1])<sum) cout << "NO\n";
        else cout << "YES\n";
    }
}