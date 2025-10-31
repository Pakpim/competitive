#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    int n,q,cnt=0;
    cin >> n >> q >> s;
    int tmp=0;
    for (auto e:s){
        if (e=='A') tmp=1;
        else if (e=='B' && tmp==1) tmp=2;
        else if (e=='C' && tmp==2) tmp=3;
        else tmp=0;
        if (tmp==3) cnt++;
    }
    while (q--){
        int x;
        char c;
        cin >> x >> c;
        x--;
        if (x-2>=0 && s[x-2]=='A' && s[x-1]=='B' && s[x]=='C') cnt--;
        if (x-1>=0 && x+1<n && s[x-1]=='A' && s[x]=='B' && s[x+1]=='C') cnt--;
        if (x+2<n && s[x]=='A' && s[x+1]=='B' && s[x+2]=='C') cnt--;
        s[x]=c;
        if (x-2>=0 && s[x-2]=='A' && s[x-1]=='B' && s[x]=='C') cnt++;
        if (x-1>=0 && x+1<n && s[x-1]=='A' && s[x]=='B' && s[x+1]=='C') cnt++;
        if (x+2<n && s[x]=='A' && s[x+1]=='B' && s[x+2]=='C') cnt++;
        cout << cnt << '\n';
    }
}