#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=20;
int n;
string s;
set<string> ss;

void rec(int r,int a,int b,int c){
    if (r==n){
        ss.emplace(s);
        return;
    }
    if (a){
        s[r]='A';
        rec(r+1,a-1,b,c);
    }
    if (b){
        s[r]='B';
        rec(r+1,a,b-1,c);
    }
    if (c){
        s[r]='C';
        rec(r+1,a,b,c-1);
    }
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int a,b,c;
    cin >> n >> a >> b >> c;
    for (int i=0;i<n;i++) s+=' ';
    rec(0,a,b,c);
    cout << ss.size() << '\n';
    for (auto e:ss) cout << e << '\n';
}