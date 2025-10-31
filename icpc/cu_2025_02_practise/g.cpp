#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using db=double;
const int N=1e5+5;
ll b[N];
ll f[N],m[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    ll s1=0,c1=0,s2=0,c2=0;
    for (int i=0;i<n;i++){
        db a;
        cin >> a;
        b[i]=a*1e5;
        b[i]/=1e5;
        m[i] = a<0;
        f[i] = a!=b[i];
        if (m[i]){
            s1+=-b[i];
        }
        else{
            s2+=b[i];
        }
    }
    for (int i=0;i<n;i++){
        // cout << i << " : " << m[i] << ' ' << b[i] << '\n';
        if (m[i]){
            if (s1<s2 && f[i]){
                s1++;
                b[i]-=1;
            }
        }
        else{
            if (s2<s1 && f[i]){
                s2++;
                b[i]+=1;
            }
        }
        cout << b[i] << '\n';
    }
}