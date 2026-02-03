#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,cnt=1,sum=0;
    cin >> n >> m;
    vector<int> v(n);
    for (auto &e:v) {
        cin >> e;
        if (sum+e>m){
            sum=0;
            cnt++;
        }
        sum+=e;
    }
    cout << cnt;
}