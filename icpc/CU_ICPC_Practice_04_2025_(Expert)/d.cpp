#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=2e5+5;
ll a[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,m,sum=0;
    cin >> n >> m;
    for (int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    int p=0;
    ll f=0;
    for (int i=n-1;i>=p;i--){
        if (i==p){
            sum+=a[i]+1;
            f=0;
        }
        else if (a[i]+a[p]>m){
            sum+=a[i]+1;
            f=0;
        }
        else{
            sum+=a[i]+a[p];
            p++;
            f=1;
        }
    }
    sum+=f;
    cout << sum;
}