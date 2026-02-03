#include <bits/stdc++.h>
using namespace std;

int a[1005][15];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    cout << n/m + bool(n%m);
}