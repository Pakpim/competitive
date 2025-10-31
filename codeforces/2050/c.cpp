#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using db=double;
const ll N=2e5+5;

bool solve(){
    string s;
    cin >> s;
    int sum=0,c2=0,c3=0;
    for (auto e:s){
        sum+=e-'0';
        c2+=(e=='2');
        c3+=(e=='3');
    }
    sum%=9;
    // if (!sum) return true;
    // int i=1;
    // while (c2*2+c3*6>=i*9-sum){
    //     ll nv=i*9-sum;
    //     // cout << " => " << nv << '\n';
    //     if (nv%2==0){
    //         nv/=2;
    //         ll nr=nv%3;
    //         if (nr <= c2 && (nv-nr)/3 <=c3+(c2-nr)/3) return true;
    //     }
    //     i++;
    // }
    if (sum==0) return true;
    if (sum==1 && ((c3==0 && c2>3) || (c3>0 && c2>0))) return true;
    if (sum==2 && ((c3==0 && c2>7) || (c3==1 && c2>4) || (c3>1 && c2>1))) return true;
    if (sum==3 && ((c3==0 && c2>2) || (c3>0))) return true;
    if (sum==4 && ((c3==0 && c2>6) || (c3==1 && c2>3) || (c3>1 && c2>0))) return true;
    if (sum==5 && ((c2>1))) return true;
    if (sum==6 && ((c3==0 && c2>5) || (c3==1 && c2>2) || (c3>1))) return true;
    if (sum==7 && ((c2>0))) return true;
    if (sum==8 && ((c3==0 && c2>4) || (c3>0 && c2>1))) return true;
    return false;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        if(solve()) cout << "YES\n";
        else cout << "NO\n";
    }
}