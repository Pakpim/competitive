#include<bits/stdc++.h>
using namespace std;

int a[15];

signed main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i=1;i<11;i++){
        a[(111*i)%11]=111*i;
    }
    if (a[n%11]>n) cout << "NO";
    else cout << "YES";
}