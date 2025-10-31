#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll M=1e9+7,N=2e5+5;
ll a[N],b[N];

ll bp (ll a,ll b){
    ll re=1;
    while (b){
        if (b&1) re*=a,re%=M;
        a*=a; a%=M;
        b>>=1;
    }
    return re;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        ll n,sum=0;
        deque<pair<ll,ll>> dq;
        cin >> n;
        for (int i=1;i<=n;i++){
            cin >> a[i];
            b[i]=0;
            while (a[i]%2==0){
                b[i]++;
                a[i]/=2;
            }
            if (dq.empty() && b[i]==0){
                sum+=a[i];
                sum%=M;
            }
            else{

                ll cnt=b[i];
                while (!dq.empty() && (dq.back().first <= a[i]*bp(2,cnt) || cnt>32) ){
                    auto [nv,np]=dq.back();
                    dq.pop_back();
                    sum-=(nv*bp(2,np))%M;
                    sum=(sum+M)%M;
                    sum+=nv; sum%=M;
                    cnt+=np;
                }
                if (cnt==0){
                    sum+=a[i];
                    sum%=M;
                }
                else{
                    dq.emplace_back(a[i],cnt);
                    sum+=(a[i]*bp(2,cnt))%M;
                    sum%=M;
                }
            }
            // cout << i << " => " << a[i] << ' ' << b[i] << ' ' << sum << '\n';
            // for (auto [x,y]:dq) cout << " -> " << x << ' ' << y << '\n';
            cout << sum << ' ';
        }
        cout << '\n';
    }
}