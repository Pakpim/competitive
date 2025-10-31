#include <map>
#include <iostream>
using namespace std;
using ll=long long;
const ll N=200005;
ll ar[50];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while (t--){
        ll n,k;
        cin >> n >> k;
        ll a=0;
        for (ll i=0;i<32;i++){
            ll l=0,r=5e8,mid,mx=0;
            while (l<=r){
                mid=l+(r-l)/2;
                if ((1<<i)*(mid*2+1)>n) r=mid-1;
                else{
                    mx=max(mx,mid);
                    l=mid+1;
                }
            }
            ar[i]=mx;
        }
        for (ll i=0;i<32;i++){
            // cout << " => " << i << ' ' << ar[i] << ' ' << k << '\n';
            if (k-(ar[i]+1)>0) k-=ar[i]+1;
            else{
                cout << (1ll<<i)*((k-1)*2+1) << '\n';
                break;
            }
        }
    }

}
