#include <bits/stdc++.h>
using namespace std;

int n,l,r,sz[50],cnt=0;

int cal3 (int np,int nk){
    if (np<=nk) return 0;
    np-=nk+1;
    return 1+np/(2*nk+2);
}

void cal2 (int nn,int nd){
    if (nn&1){
        cnt+=cal3(r,sz[nd+1]);
        cnt-=cal3(l-1,sz[nd+1]);
    }
    if (nn<2) return;
    cal2(nn/2,nd+1);
}

void cal1 (int nn,int nd){
    if (nn==0 || nn==1){
        sz[nd]=1;
        return;
    }
    cal1(nn/2,nd+1);
    sz[nd]=sz[nd+1]*2+1;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> l >> r;
    cal1(n,0);
    cal2(n,0);
    cout << cnt;
}