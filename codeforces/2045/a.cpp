#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    int v=0,c=0,n=0,g=0,y=0;
    for (auto e:s){
        if (e=='N') n++;
        else if (e=='G') g++;
        else if (e=='Y') y++;
        else if (e=='A' || e=='E' || e=='I' || e=='O' || e=='U') v++;
        else c++;
    }
    int ng=min(n,g),ans=0;
    if (n>g) c+=n-ng;
    else c+=g-ng;
    for (int i=0;i<=ng;i++){
        for (int j=0;j<=y;j++){
            int nv=v+j,nc=c+(ng-i)*2+(y-j),ns=0;
            ns+=5*min(i/2,nv);
            nv-=min(i/2,nv);
            ns+=4*min({i%2,nv,nc});
            nv-=min({i%2,nv,nc});
            nc-=min({i%2,nv,nc});
            ns+=3*min(nc/2,nv);
            ans=max(ans,ns);
        }
    }
    cout << ans;
}