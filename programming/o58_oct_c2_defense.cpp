#include <bits/stdc++.h>
using namespace std;

const int N=3005;
int c[N],d[N];
deque <pair<int,int>> dq;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k,ans=1e9;
    cin >> n >> k;
    for (int i=1;i<=n;i++) cin >> c[i];
    int mn=c[1];
    for (int i=2;i<=min(n,k);i++){
        d[i]=c[i]+mn;
        while (!dq.empty() && dq.back().second>=d[i]) dq.pop_back();
        dq.emplace_back(i,d[i]);
        mn=min(mn,c[i]);
    }
    for (int i=k+1;i<=n;i++) {
        d[i]=c[i];
        while (!dq.empty() && dq.front().first<=i-k) dq.pop_front();
        d[i]+=dq.front().second;
        while (!dq.empty() && dq.back().second>=d[i]) dq.pop_back();
        dq.emplace_back(i,d[i]);
    }
    mn=c[n];
    for (int i=n-1;i>max(1,n-k);i--){
        ans=min(ans,d[i]+mn);
        mn=min(mn,c[i]);
    }
    mn=c[min(n,k)];
    for (int i=min(n,k)-1;i>max(0,n-k);i--){
        ans=min(ans,c[i]+mn);
        mn=min(mn,c[i]);
    }
    cout << ans;
}