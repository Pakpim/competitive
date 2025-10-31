#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,s;
    cin >> n >> s;
    if (s==0){
        if (n==1) cout << "0 0";
        else cout << "-1 -1";
        exit(0);
    }
    if (s>n*9){
        cout << "-1 -1";
        exit(0);
    }
    vector<int> mn(n,0), mx(n,0);
    int ns=s-1,np=n-1;
    mn[0]=1;
    while (ns){
        int nv=min(9-mn[np],ns);
        ns-=nv;
        mn[np]+=nv;
        np--;
    }
    ns=s; np=0;
    while (ns){
        int nv=min(9-mx[np],ns);
        ns-=nv;
        mx[np]+=nv;
        np++;
    }
    for (auto e:mn) cout << e;
    cout << ' ';
    for (auto e:mx) cout << e;
}