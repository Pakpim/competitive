#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using db=double;
using pll=pair<ll,ll>;
const ll N=2e5+5;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    char a,b;
    string s;
    cin >> n >> a >> b >> s;
    for (auto &e:s) if (e!=a) e=b;
    cout << s;
}