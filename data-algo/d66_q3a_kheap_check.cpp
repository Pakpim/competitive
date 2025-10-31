#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int ar[50005];

string ans (){
    int n,k;
    cin >> n >> k;
    for (int i=0;i<n;i++) cin >> ar[i];
    for (int i=0;i<n;i++){
        if (i && ar[(i-1)/k]<ar[i]) return "false\n";
    }
    return "true\n";
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        cout << ans();
    }
}