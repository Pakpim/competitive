#include <bits/stdc++.h>
using namespace std;

const int N=4e5+5;
int pi[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    string a,b;
    cin >> n >> a;
    b = a;
    reverse(b.begin(), b.end());
    a = b + "#" + a;
    for (int i=1;i<a.size();i++){
        int j=pi[i-1];
        while (j>0 && a[i]!=a[j]) j=pi[j-1];
        if (a[i]==a[j]) j++;
        pi[i]=j;
    }
    cout << n-pi[a.size()-1];
}