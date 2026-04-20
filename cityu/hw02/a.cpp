#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    int sum=0, cnt=0;
    for (auto e:s) if (e!='-'){
        cnt++;
        sum+=cnt*(e-'0');
    }
    sum-=cnt*(s[s.size()-1]-'0');
    string a=s;
    a[a.size()-1]=sum%11+'0';
    if (sum%11==10) a[a.size()-1]='X';
    bool ok=s==a;
    cout << (ok? "Right":a);
}