#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=2e5+5;
ll a[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        ll n,cnt=0,tmp=0;
        cin >> n;
        for (int i=0;i<n;i++) cin >> a[i];
        sort(a,a+n);
        for (int i=0;i<n;i++){
            if (a[i]<=tmp) continue;
            else {
                tmp++;
                cnt+=a[i]-tmp;
            }
        }
        cout << cnt << '\n';
    }
}