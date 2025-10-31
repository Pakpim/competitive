#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using ti=tuple<ll,ll,ll>;
const ll N=2e5+5;
ll ar[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while (t--){
        ll n,m;
        cin >> n >> m;
        vector<ll> v1(n),v2(m);
        for (auto &e:v1) cin >> e;
        for (auto &e:v2) cin >> e;
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        if (n>m){
            swap(n,m);
            swap(v1,v2);
        }
        ll k=min(n,m-n);
        if (m-n<n) k+=((n-(m-n))/3)*2;
        if ((n-(m-n))%3 == 2) k++;
        cout << k << '\n';
        priority_queue<ll,vector<ll>,greater<ll>> pq1,pq2;
        ll c1=n,c2=m,l1=0,r1=n-1,l2=0,r2=m-1,sum=0;
        for (ll i=0;i<k;i++){
            ll nv=-1e18,tg=0,md=0;
            if (c1>1 && c2){
                ll tmp=v1[r1]-v1[l1];
                if (nv<tmp){
                    nv=tmp;
                    tg=1;
                    md=1;
                }
            }
            if (c2>1 && c1){
                ll tmp=v2[r2]-v2[l2];
                if (nv<tmp){
                    nv=tmp;
                    tg=2;
                    md=1;
                }
            }
            else if (c1>2 && !pq2.empty()){
                ll tmp=0;
                tmp-=pq2.top();
                tmp+=v1[r1]+v1[r1-1]-v1[l1]-v1[l1+1];
                if (nv<tmp){
                    nv=tmp;
                    tg=1;
                    md=2;
                }
                
            }
            else if (c2>2 && !pq1.empty()){
                ll tmp=0;
                tmp-=pq1.top();
                tmp+=v2[r2]+v2[r2-1]-v2[l2]-v2[l2+1];
                if (nv<tmp){
                    nv=tmp;
                    tg=2;
                    md=2;
                }
            }
            if (tg==1 && md==1){
                pq1.emplace(v1[r1]-v1[l1]);
                r1--; l1++; c1-=2; c2--;
            }
            else if (tg==2 && md==1){
                pq2.emplace(v2[r2]-v2[l2]);
                r2--; l2++; c2-=2; c1--;
            }
            else if (tg==1 && md==2){
                pq1.emplace(v1[r1]-v1[l1]);
                l1++; r1--; 
                pq1.emplace(v1[r1]-v1[l1]);
                l1++; r1--;
                l2--; r2++;
                c1-=3;
                pq2.pop();
            }
            else{
                pq2.emplace(v2[r2]-v2[l2]);
                l2++; r2--; 
                pq2.emplace(v2[r2]-v2[l2]);
                l2++; r2--;
                l1--; r1++;
                c2-=3;
                pq1.pop();
            }
            // cout << " => " << nv << ' ' << tg <<  ' ' << md << ' ' << c1 << ' ' << c2 << '\n';
            sum+=nv;
            cout << sum << ' ';
        }
        cout << '\n';
    }
}