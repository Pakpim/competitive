#include <bits/stdc++.h>
using namespace std;

const int N=5005;

int ask (int i,int j){
    cout << "? " << i << ' ' << j << '\n';
    // cout.flush();
    fflush(stdout);
    int re;
    cin >> re;
    return re;
}

int main (){
    // ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int a[N];
    int x=ask(1,2);
    int y=ask(2,3); 
    int z=ask(1,3);
    a[1]=(x-y+z)/2;
    a[3]=z-a[1];
    a[2]=y-a[3];
    for (int i=4;i<=n;i++){
        int nv=ask(1,i);
        a[i]=nv-a[1];
    }
    cout << "! ";
    for (int i=1;i<=n;i++) cout << a[i] << ' ';
    cout << '\n';
    fflush(stdout);
    return 0;
    // cout.flush();
}