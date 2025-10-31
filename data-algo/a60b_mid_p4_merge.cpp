#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int n,k,a[N],cnt=1;

void cal (int l,int r){
    int mid=(l+r)/2;
    if (cnt==k){
        for (int i=1;i<=n;i++) cout << a[i] << ' ';
        exit(0);
    }
    if (l==r-1) return;
    cnt+=2;
    swap(a[mid-1],a[mid]);
    cal(l,mid);
    cal(mid,r);
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    if (!(k&1)){
        cout << "-1";
        return 0;
    }
    for (int i=1;i<=n;i++) a[i]=i;
    cal(1,n+1);
    cout << "-1";
}