#include <bits/stdc++.h>
using namespace std;

const int N=1000005;
int ar[N],ans[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> ar[i];
    if (n&1){

    }
    else {
        ans[1]=(ar[1]+n/2)%n;
        if (ans[1]==0) ans[1]=n;
        for (int i=2;i<=n;i++){
            ans[i]=ar[i];
        }
    }
    for (int i=1;i<=n;i++) cout << ans[i] << ' ';
}