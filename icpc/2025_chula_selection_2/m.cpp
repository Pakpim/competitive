#include <bits/stdc++.h>
using namespace std;

int ask (int k,int r1,int c1, int r2,int c2){
    cout << "? " << k << ' ' << r1 << ' ' << c1 << ' ' << r2 << ' ' << c2 << '\n';
    cout.flush();
    int re;
    cin >> re;
    return re;
}

void ans(int r,int c){
    cout << "! " << r << ' ' << c << '\n';
    cout.flush();
}

void solve(){
    int n, m;
    int p[5]={19,17,15,14,13};
    cin >> n >> m;
    int k=-1;
    for (int i=0;i<5;i++){
        int nv=ask(p[i],1,1,n,m);
        if (nv!=0){
            k=p[i];
            break;
        }
    }
    int l=1,r=n,mid;
    while (l<r){
        mid=l+(r-l)/2;
        int nv=ask(k,1,1,mid,m);
        if (nv){
            r=mid;
        }
        else l=mid+1;
    }
    int tn=l;
    l=1; r=m;
    while (l<r){
        mid=l+(r-l)/2;
        int nv=ask(k,tn,1,tn,mid);
        if (nv){
            r=mid;
        }
        else l=mid+1;
    }
    int tm=l;
    ans(tn,tm);
}

int main (){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}