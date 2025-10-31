#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=2e5+5;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n,m,k;
        string s;
        int cnt=0,ans=0; 
        cin >> n >> m >> k >> s;
        for (int i=0;i<s.size();){
            if (s[i]=='0') cnt++;
            else cnt=0;
            if (cnt==m){
                ans++;
                // cout << " => " << i << '\n';
                for (int j=i;j<min(i+k,int(s.size()));j++) s[j]='1';
                i+=k;
                cnt=0;
            }
            else i++;
        }
        cout << ans << '\n';
    }
}