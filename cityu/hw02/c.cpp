#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using lll=__int128_t;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll _n;
    string _k;
    cin >> _n >> _k;
    lll n,k=0;
    n=_n;
    for (auto e:_k){
        k=(k*(lll(10)))+lll(e-'0');
    }
    // cout << ll(n) << ' ' << ll(k) << '\n';
    bool rev=0;
    while (n){
        // cout << " => " << n << ' ' << (1ll<<(n-1)) << ' ' << k << ' ' << rev << ' ' << '\n';
        if ((lll(1))<<(n-1) <= k){
            cout << (rev^1);
            rev=1;
            k-=(lll(1))<<(n-1);
        }
        else{
            cout << rev;
            rev=0;
        }
        n--;
    }
}

/*
00011000111111010000001001001000000001100011
00011000111111010000001001001000000001100011%
*/