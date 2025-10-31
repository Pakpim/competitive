//Petrozavodsk Winter 2020. Day 9. Yuhao Du Contest 7 H. Heavy Stones
#include <bits/stdc++.h>
#define mid (l+r)/2;
#define lc i*2+1
#define re i*2+2
using namespace std;

using ll=long long;
using db=double;
const int N=2e5+5;
ll a[N],n,b[N];
deque<pair<ll,ll>> dq1,dq2;
vector<pair<ll,ll>> rm[N];
vector<tuple<db,ll,ll>> st;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=n-1;i>=0;i--){
        ll v0=1,v1=a[i];
        b[i]=a[i]+b[i+1];
        while (!dq2.empty() && db(dq2.front().second)/db(dq2.front().first) >= db(v1)/db(v0)){
            auto [n0,n1]=dq2.front();
            dq2.pop_front();
            b[i]+=v1*n0;
            rm[i].emplace_back(n0,n1);
            v0+=n0;
            v1+=n1;
        }
        dq2.emplace_front(v0,v1);
    }
    ll sum=0;
    for (int i=0;i<n;i++){
        sum+=a[i];
        if (i){
            ll v0=1,v1=a[i+1];
            while (!dq1.empty() && db(dq1.front().second)/db(dq1.front().first) >= db(v1)/db(v0)){
                auto [n0,n1]=dq2.front();
                dq1.pop_front();
                sum+=v1*n0;
                v0+=n0;
                v1+=n1;
            }
            dq1.emplace_front(v0,v1);
        }
        cout << sum << ' ';
    }
}