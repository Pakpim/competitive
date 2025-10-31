#include <bits/stdc++.h>
using namespace std;

const int N=100005,L=55;
int k[L];
set<string> a;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,l;
    cin >> n >> m >> l;
    for (int i=0;i<l;i++) cin >> k[i];
    while (n--){
        string s;
        cin >> s;
        a.emplace(s);
    }
    while (m--){
        string s;
        cin >> s;
        for (int i=0;i<l;i++) s[i]=(s[i]-'a'+k[i])%26+'a';
        if (a.find(s)!=a.end()) cout << "Match\n";
        else cout << "Unknown\n";
    }
}