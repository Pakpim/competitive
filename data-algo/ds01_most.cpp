#include<bits/stdc++.h>
using namespace std;

map<string,int> m;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,mx=0;
    string s,t;
    cin >> n;
    while (n--){
        cin >> s;
        m[s]++;
        if (mx<m[s]) mx=m[s],t=s;
        if (mx==m[s]) t=max(t,s);
    }
    cout << t << ' ' << mx;
}