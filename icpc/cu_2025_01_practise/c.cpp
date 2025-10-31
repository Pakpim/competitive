#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll N=105;
ll a[N],b[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n;
    cin >> n;
    while (n--){
        int v;
        cin >> v;
        a[v]++;
    }
    cin >> n;
    while (n--){
        int v;
        cin >> v;
        b[v]++;
    }
    ll cnt=0;
    for (int i=1;i<=100;i++){
        ll nv=min(a[i],b[i-1]);
        cnt+=nv;
        a[i]-=nv;
        nv=min(a[i-1],b[i]);
        cnt+=nv;
        b[i]-=nv;
        nv=min(a[i],b[i]);
        cnt+=nv;
        a[i]-=nv;
        b[i]-=nv;
    }
    cout << cnt;
}