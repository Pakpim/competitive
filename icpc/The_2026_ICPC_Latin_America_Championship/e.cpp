#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int mn=-1, mx=1e9;
    bool f=1;
    int q;
    cin >> q;
    while (q--){
        int a,b;
        char c;
        cin >> a >> b >> c;
        int mid=(a+b)/2, sz=(b-a+1);
        // cout << " ? " << sz << '\n';
        if (sz%2==0){
            if (c=='E'){
                f=0;
            }
            if (c=='A'){
                mx=min(mx,mid);
            }
            if (c=='B'){
                mn=max(mn,mid+1);
            }
        }
        else{
            if (c=='E'){
                if (mn>mid) f=0;
                if (mx<mid) f=0;
                mn=max(mn,mid);
                mx=min(mx,mid);
            }
            if (c=='A'){
                mx=min(mx,mid-1);
            }
            if (c=='B'){
                mn=max(mn,mid+1);
            }
        }
    }
    if (mn>mx) f=0;
    if (!f) cout << "*";
    else cout << mn << ' ' << mx;
}