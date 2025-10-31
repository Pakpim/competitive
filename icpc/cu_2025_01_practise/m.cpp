#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll N=1e6+5,inf=1e8;
ll qs[N],l[N*2],mx,cnt=1;
deque<ll> dq;
string s;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> s;
    int n=s.size();
    for (int i=-n;i<=n;i++) l[i+n]=inf;
    l[0+n]=0;
    dq.emplace_back(0);
    for (int i=1;i<=n;i++){
        qs[i]=qs[i-1]+(s[i-1]=='('? 1:-1);
        ll nv=-1;
        if (l[qs[i]+n]!=inf) nv=i-l[qs[i]+n];
        if (nv>mx){
            mx=nv;
            cnt=0;
        }
        if (nv==mx) cnt++;
        while (!dq.empty() && qs[dq.back()]>qs[i]){
            l[qs[dq.back()]+n]=inf;
            dq.pop_back();
        }
        if (l[qs[i]+n]>i){
            dq.emplace_back(i);
            l[qs[i]+n]=i;
        }
    }
    cout << mx << ' ' << cnt << '\n';
}