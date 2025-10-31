#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int h[N],p[N],s[N];

int main (){
    // ios::sync_with_stdio(0); fin.tie(0);
    ifstream fin;
    fin.open("hps.in");
    int n,mx=0;
    fin >> n;
    for (int i=1;i<=n;i++){
        h[i]=h[i-1]; p[i]=p[i-1]; s[i]=s[i-1];
        char c;
        fin >> c;
        if (c=='H') h[i]++;
        if (c=='P') p[i]++;
        if (c=='S') s[i]++;
    }
    for (int i=1;i<=n;i++){
        int h2=h[n]-h[i], p2=p[n]-p[i], s2=s[n]-s[i];
        int nv=max({h[i],p[i],s[i]})+max({h2,p2,s2});
        mx=max({mx,nv});
    }
    ofstream fout;
    fout.open ("hps.out");
    fout << mx;
    fout.close();
}