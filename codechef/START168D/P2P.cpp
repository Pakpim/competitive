#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        bool o=0,e=1;
        string a,b;
        cin >> n >> a >> b;
        for (int i=0;i<n;i++){
            bool no=0,ne=0;
            if (a[i]=='0' || b[i]=='0')  no|=o,ne|=e;
            if (a[i]=='1' || b[i]=='1')  no|=e,ne|=o;
            o=no;
            e=ne;
        }
        if (o) cout << "YES\n";
        else cout << "NO\n";
    }
}