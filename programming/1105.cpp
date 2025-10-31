#include <bits/stdc++.h>
using namespace std;

const int N=2e6+5;
bool f[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k,cnt=0;
    cin >> n >> k;
    for (int i=1;i<=n;i++){
        int v;
        cin >> v;
        f[v]=1;
    }
    for (int i=N-1;i>0;i--){
        if (f[i]) cnt++;
        if (cnt==k){
            cout << i;
            return 0;
        }
    }
}