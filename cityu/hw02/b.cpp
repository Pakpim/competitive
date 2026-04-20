#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    bool b;
    int n;
    cin >> s >> b >> n;
    if (!b){
        for (auto &e:s) if (e>='A' && e<='Z') e=e-'A'+'a';
    }
    while (n--){
        string a, t;
        cin >> t;
        a=t;
        if (!b){
            for (auto &e:a) if (e>='A' && e<='Z') e=e-'A'+'a';
        }
        bool f=0;
        for (int i=0;i+s.size()-1<a.size();i++){
            bool ok=1;
            for (int j=0;j<s.size();j++) ok&=(s[j]==a[i+j]);
            if (ok){
                f=1;
                break;
            }
        }
        if (f) cout << t << '\n';
    }
}