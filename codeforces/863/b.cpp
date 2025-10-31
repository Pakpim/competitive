#include <bits/stdc++.h>
using namespace std;

const int N=105;
int a[N],qs[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i=1;i<=n*2;i++) cin >> a[i];
    sort(a+1,a+2*n+1);
    for (int i=1;i<=n*2;i++){
        qs[i]=qs[i-1];
        if (i&1) qs[i]-=a[i];
        else qs[i]+=a[i];
    }
    int mn=1e9;
    for (int i=1;i<=n*2;i++){
        for (int j=1;j<i;j++){
            int nv=qs[j-1]+qs[n*2]-qs[i]-qs[i-1]+qs[j];
            mn=min(mn,nv);
        }
    }
    cout << mn;
}