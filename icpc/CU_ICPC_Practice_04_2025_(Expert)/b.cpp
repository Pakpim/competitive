#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n,p=0,i=0;
        string s;
        bool ok=1;
        cin >> n >> s;
        while (p<n){
            if (i&1){
                if (p+1==n){
                    ok=0;
                    break;
                }
                if (s[p]!=s[p+1]) ok=0;
                i++;
                p+=2;
            }
            else{
                p++;
                i++;
            }
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
}