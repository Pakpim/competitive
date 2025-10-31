#include<bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int x,y,k;
        cin >> x >> y >> k;
        int tmp = ceil((double(k))/sqrt(2));
        cout << "0 0 "<< tmp << ' ' << tmp << '\n';
        cout << "0 " << tmp << ' ' << tmp << ' ' << "0\n";
    }
}