#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        string a,b;
        cin >> a >> b;
        int ans=a.size()+b.size();
        for (int i=0;i<b.size();i++){
            int p=i;
            for (int j=0;j<a.size();j++){
                if (p<b.size() && a[j]==b[p]) p++;
            }
            ans=min(ans,int (a.size()+i+b.size()-p));
        }
        cout << ans << '\n';
    }
}