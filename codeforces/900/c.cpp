#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int a[N], cnt[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, fmx=-1, smx=-1;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        if (fmx>a[i] && smx<a[i]) cnt[fmx]++;
        if (fmx<a[i]) cnt[a[i]]--;
        smx=max(smx,a[i]);
        if (smx>fmx) swap(smx,fmx);
    }
    int mx=-1e9, tg=-1;
    for (int i=1;i<=n;i++){
        if (mx<cnt[i]){
            mx=cnt[i];
            tg=i;
        }
    }
    cout << tg;
}