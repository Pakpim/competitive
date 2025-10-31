#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin >> n >> k;
    for (int i=0;i<1<<n;i++){
        int cnt=0,mx=0;
        for (int j=0;j<n;j++){
            if (i>>j&1) cnt++;
            else cnt=0;
            mx=max(mx,cnt);
        }
        if (mx<k) continue;
        for (int j=n-1;j>=0;j--) cout << (i>>j&1);
        cout << '\n';
    }
    
}