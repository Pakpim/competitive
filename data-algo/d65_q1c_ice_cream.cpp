#include <bits/stdc++.h>
using namespace std;

const int N=100005;
int n,m,sum[N],ar[N];
int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> ar[0];
    for (int i=1;i<=n;i++){
        int a,b;
        cin >> a >> b;
        ar[a]=b;
    }
    sum[0]=ar[0];
    for (int i=1;i<N;i++){
        if (!ar[i]) ar[i]=ar[i-1];
        sum[i]=sum[i-1]+ar[i];
    }
    while (m--){
        int p,x;
        cin >> p >> x;
        auto it1 = lower_bound(sum,sum+x+1,p);
        auto it2 = lower_bound(sum+x,sum+N,p+sum[x]);
        if (it1==sum+x+1) cout << it2-sum << ' ';
        else cout << it1-sum << ' ';
    }
}