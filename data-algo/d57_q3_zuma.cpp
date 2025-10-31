#include <bits/stdc++.h>
using namespace std;

const int N=1e6+5;
int a[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k,v;
    cin >> n >> k >> v;
    k++;
    a[k]=v; a[0]=-1; a[n+2]=-1;
    for (int i=1;i<k;i++) cin >> a[i];
    for (int i=k+1;i<=n+1;i++) cin >> a[i];
    int pl=k-1,pr=k+1,cnt=1,c=v,tl=n+2,tr=0;
    while (pl>0 || pr<n+2){
        if (a[pl]!=c && a[pr]!=c){
            if (cnt<3) break;
            tl=pl+1; tr=pr-1;
            if (a[pl]!=a[pr] || pl==0 || pr==n+2) break;
            c=a[pl];
            cnt=0;
        }
        if (a[pl]==c){
            cnt++;
            pl--;
        }
        if (a[pr]==c){
            cnt++;
            pr++;
        }
    }
    if (cnt>=3) {
        tl=pl+1; tr=pr-1;
    }
    for (int i=1;i<=n+1;i++) if (i<tl || i>tr) cout << a[i] << ' ';
}
