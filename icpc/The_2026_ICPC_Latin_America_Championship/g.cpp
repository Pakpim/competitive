#include <bits/stdc++.h>
using namespace std;

const int N=205;
int ac[N], ag[N], cc[N], cg[N];

void solve(){
    int g,c;
    cin >> g >> c;
    for (int i=0;i<N;i++) cc[i]=cg[i]=0;
    for (int i=N-1;i>0;i--){
        while (c>=ac[i]){
            c-=ac[i];
            cc[i]++;
        }
    }
    for (int i=N-1;i>0;i--){
        while (g>=ag[i]){
            g-=ag[i];
            cg[i]++;
        }
    }
    for (int i=N-1;i>0;i--){
        for (int j=0;j<cc[i];j++) cout << "C";
        for (int j=0;j<cg[i];j++) cout << "G";
        cout << "AT";
    }
    cout << "A\n";
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    for (int i=1;i<N;i++){
        ac[i]=i*(i+1)/2;
        // cout << ac[i] << ' ';
    }
    for (int i=1;i<N;i++){
        ag[i]=i*(i+1)*(i+2)/6;
    }
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}