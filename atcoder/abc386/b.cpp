#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    int cnt=0,ans=0;
    for (auto e:s){
        if (e!='0'){
            ans++;
            ans+=cnt/2+cnt%2;
            cnt=0;
        }
        else{
            cnt++;
        }
    }
    ans+=cnt/2+cnt%2;
    cnt=0;
    cout << ans;
}