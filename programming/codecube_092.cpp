#include <bits/stdc++.h>
using namespace std;

const int N=100005;
int ans[N];
double cnt;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    for (int i=1;i<N;i++){
        cnt+=log10(i);
        ans[i]=ceil(cnt);
    }
    int q;
    cin >> q;
    while (q--){
        int x;
        cin >> x;
        cout << ans[x] << '\n';
    }
}