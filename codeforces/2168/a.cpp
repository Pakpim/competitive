#include <bits/stdc++.h>
using namespace std;

using ll=long long;

void dec(){
    string s;
    cin >> s;
    int n=s.size();
    cout << n/10 << '\n';
    for (int i=0;i<n;i+=10){
        int a=0;
        for (int j=i+9;j>=i;j--){
            a=a*26+(s[j]-'a');
        }
        cout << a << ' ';
    }
    cout << '\n';
}

void enc(){
    int n;
    cin >> n;
    vector<int> v;
    for (int i=0;i<n;i++){
        int a;
        cin >> a;
        for (int j=0;j<10;j++){
            v.emplace_back(a%26);
            a/=26;
        }
    }
    for (auto e:v) cout << char('a'+e);
    cout << '\n';
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    string t;
    cin >> t;
    if (t=="first") enc();
    else dec();
}