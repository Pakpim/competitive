#include <iostream>
using namespace std;
using ll=long long;
const ll N=200005;
ll s1[N],sum[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    for (int i=1;i<N;i++){
        s1[i]=s1[i/10]+i%10;
        sum[i]=sum[i-1]+s1[i];
    }
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        cout << sum[n] << '\n';
    }
}