#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=1e5+5;
ll a[N],b[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<m;i++) cin >> b[i];
    vector<ll> v;
    for (int i=0;i<m;i++){
        if (v.empty() || b[i]<v[v.size()-1]) v.emplace_back(b[i]);
    }
    for (int i=0;i<n;i++){
        ll p=0;
        while (p<v.size()){
            ll l=p,r=v.size()-1,mid,tg=1e9;
            while (l<=r){
                mid=(l+r)/2;
                if (v[mid]<=a[i]){
                    tg=min(tg,mid);
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            if (tg==1e9){
                break;
            }
            else{
                // cout << "? " << a[i] << ' ' << p << " = ";
                a[i]%=v[tg];
                p=tg;
                // cout << a[i] << ' ' << p << '\n';
            }
        }
        cout << a[i] << ' ';
    }
    
}