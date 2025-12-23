#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=1e7+5, inf=1e9, M=104206969;
bool f[N];
vector<pair<ll,ll>> p, p2, p4;

ll solve(){
    ll n,k;
    cin >> n >> k;
    if (k==0) return 1;
    if (k==1) return n;
    if (k==2){
        ll re=0;
        auto it=upper_bound(p.begin(), p.end(), make_pair(n,0ll));
        if (it==p.begin()) return 0;
        it--;
        re=(it-p.begin()+1)*n; re%=M;
        re-=it->second;
        if (re<0) re+=M;
        return re;
    }
    if (k==3){
        ll re=0;
        auto it=upper_bound(p2.begin(), p2.end(), make_pair(n,0ll));
        if (it==p2.begin()) return 0;
        it--;
        // cout << " ? " << it->first << ' ' << it->second << '\n'; 
        re=(it-p2.begin()+1)*n; re%=M;
        re-=it->second;
        re*=2; re%=M;
        if (re<0) re+=M;
        return re;
    }
    if (k==4) return max(0ll, n-7);
    return 0;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    for (int i=2;i<N;i++){
        if (f[i]) continue;
        p.emplace_back(i,i);
        if (p.size()>1) p.back().second += p[p.size()-2].second, p.back().second%=M;
        for (int j=i*2;j<N;j+=i) f[j]=1;
    }
    for (int i=1;i+1<p.size();i++){
        if (p[i].first+2==p[i+1].first) {
            p2.emplace_back(p[i].first+2, p[i].first+2);
            if (p2.size()>1) p2.back().second += p2[p2.size()-2].second, p2.back().second%=M;
        }
    }
    for (int i=1;i+2<p.size();i++){
        if (p[i].first+2==p[i+1].first && p[i].first+4==p[i+2].first) {
            p4.emplace_back(p[i].first+4, p[i].first+4);
            if (p4.size()>1) p4.back().second += p4[p4.size()-2].second, p4.back().second%=M;
        }
    }
    // for (auto [e, e2]:p2) cout << e << ' ' << e-2 << " = " << e2 << '\n';
    // for (auto [e, e2]:p4) cout << e << ' ' << e-2 << ' ' << e-4 << " = " << e2 << '\n';
    int t=0;
    cin >> t;
    while (t--){
        cout << solve() << '\n';

    }
}