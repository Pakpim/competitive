#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,q,sum=0,l=0,r=1;
    cin >> n >> q;
    while (q--){
        char h;
        int t;
        cin >> h >> t;
        t--;
        if (h=='L'){
            if ((t-l+n)%n<(r-l+n)%n) sum+=(t-l+n)%n;
            else sum+=(l-t+n)%n;
            l=t;
        }
        else{
            if ((t-r+n)%n<(l-r+n)%n) sum+=(t-r+n)%n;
            else sum+=(r-t+n)%n;
            r=t;
        }
    }
    cout << sum;
}