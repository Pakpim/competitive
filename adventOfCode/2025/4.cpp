#include <bits/stdc++.h>
using namespace std;

using ll=long long;
string a[500];

int main (){
    ifstream fin;
    fin.open("4.txt");
    string s;
    ll idx=1, n, m;
    while (fin >> s){
        a[idx++]='.'+s+'.';
    }
    n=idx-1;
    m=a[1].size()-2;
    for (int i=0;i<=m+1;i++) a[0]=a[0]+'.';
    for (int i=0;i<=m+1;i++) a[n+1]=a[n+1]+'.';
    int cnt=0;
    bool b=1;
    while (b){
        bool f=0;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                if (a[i][j]=='.') continue;
                int nv=0;
                for (int p=-1;p<=1;p++){
                    for (int q=-1;q<=1;q++){
                        if (!p && !q) continue;
                        nv+=(a[i-p][j-q]=='@');
    
                    }
                }
                cnt+=(nv<4);
                if (nv<4){
                    f=1;
                    a[i][j]='.';
                }
                // cout << i << ' ' << j << " => " << nv << ' ' << cnt << '\n';
            }
        }
        if (!f) b=0;
    }
    // cout << n << ' ' << m << '\n';
    // for (int i=0;i<=n+1;i++) cout << a[i] << '\n';
    // cout << '\n';
    cout << cnt;
}