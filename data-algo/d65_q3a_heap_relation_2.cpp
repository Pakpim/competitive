#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int ans (){
    ll k,a,b;
    cin >> k >> a >> b;
    if (a==b) return 4;
    if (a>b) swap(a,b);
    if ((b-1)/k == a) return 1;
    ll ha=0,hb=0;
    while (b>a){
        hb++;
        b=(b-1)/k;
    }
    if (b==a) return 2;
    while (b){
        hb++;
        b=(b-1)/k;
    }
    while (a){
        ha++;
        a=(a-1)/k;
    }
    if (ha!=hb) return 3;
    return 4;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        cout << ans() << ' ';
    }
}