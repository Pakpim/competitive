#include <bits/stdc++.h>
using namespace std;

using ll=long long;

int main (){
    ifstream fin;
    fin.open("3.txt");
    string s;
    ll sum=0;
    while (fin >> s){
        int n=s.size();
        ll nv=0;
        ll l=0, r=n-12, t1=1e5;
        cout << "! " << s << " = ";
        for (ll t=0;t<12;t++){
            ll mx=0, tg=0;
            for (int i=l;i<=r;i++){
                if (s[i]-'0'>mx){
                    mx=s[i]-'0';
                    tg=i;
                }
            }
            // cout << s << ' ' << n << " => " << t << ' ' << l << ' ' << r << " : " << mx << ' ' << nv << '\n';
            l=tg+1;
            r++;
            nv=nv*10+mx;
        }
        sum+=nv;
        cout << nv << '\n';
    }
    cout << sum;
}