#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,sum=0;
    cin >> n;
    while (n--){
        string s;
        cin >> s;
        int cnt=0;
        for (auto e:s){
            if (e=='N'){
                cnt++;
            }
            else{
                sum+=cnt/2;
                cnt=0;
            }
        }
        sum+=cnt/2;
    }
    cout << sum;
}