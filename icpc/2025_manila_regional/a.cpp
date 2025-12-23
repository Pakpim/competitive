#include <bits/stdc++.h>
using namespace std;

using ll=long long;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    cin>> s;
    if (s.size()%2==0) cout << ":)";
    else cout << s[s.size()/2];
}