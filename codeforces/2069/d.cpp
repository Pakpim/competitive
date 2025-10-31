#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=2e5+5;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        int n=s.size();
        int tl=0,tr=n/2,ans=n;
        deque<int> dq[30][2];
        for (int l=0,r=n-1;l<=r;l++,r--){
            tl=max(tl,l);
            if (s[l]!=s[r]) break;
            if (l==r-1 || l==r) {
                ans=0;
            }
        }
        for (int l=n/2-1,r=n-n/2;l>=0;l--,r++){
            tr=min(tr,l);
            if (s[l]!=s[r]) break;
        }
        for (int j=0;j<2;j++){
            int mx=tl;
            for (int i=tl;i<=n-1-tl;i++) dq[s[i]-'a'][j].emplace_back(i);
            for (int i=tl;i<n/2;i++){
                if (dq[s[n-1-i]-'a'][j].empty()) continue;
                // cout << j << ' ' << i << " => " << s[n-i-1] << ' ' << dq[s[n-i-1]-'a'][j].front() << '\n';
                if (dq[s[n-1-i]-'a'][j].front()!=i) mx=max(mx,dq[s[n-1-i]-'a'][j].front());
                dq[s[n-1-i]-'a'][j].pop_front();
                dq[s[n-1-i]-'a'][j].pop_back();
            }
            ans=min(ans,mx-tl+1);
            reverse(s.begin(),s.end());
        }
        cout << ans << '\n';
    }
}

/*
5
baba
cc
ddaa
acbacddacbca
acbacdxdacbca
*/