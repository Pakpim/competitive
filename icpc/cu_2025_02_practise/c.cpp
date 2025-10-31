#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,mx=0;
    string s,tg="";
    map<pair<char,char>,int> m;
    cin >> n >> s;
    for (int i=1;i<n;i++){
        m[{s[i-1],s[i]}]++;
        if (m[{s[i-1],s[i]}]>mx){
            mx=m[{s[i-1],s[i]}];
            tg=s[i-1];
            tg+=s[i];
        }
    }
    cout << tg;
}