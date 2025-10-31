#include <bits/stdc++.h>
using namespace std;

const int N=1<<18+5;
int a[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;1<<i<=n;i++){
        for (int j=1;j<=n;j+=1<<i){
            for (int k=j;k<j+(1<<(i-1));k++){
                a[k]=a[k]+a[k+(1<<(i-1))];
                a[k+(1<<(i-1))]=a[k]-(a[k+(1<<(i-1))]<<1);
            }
        }
    }
    for (int i=1;i<=n;i++) cout << a[i] << ' ';
}