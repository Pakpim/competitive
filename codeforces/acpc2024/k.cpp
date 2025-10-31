#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n,sum;
        cin >> n;
        while (n--){
            sum=0;
            for (int i=0;i<8;i++){
                int v;
                cin >> v;
                sum+=v;
            }
            cout << sum << '\n';
        }
    }
}