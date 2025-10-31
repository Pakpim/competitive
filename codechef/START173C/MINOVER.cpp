#include <bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int a[N],b[N];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n,m,mn=1e9,id=-1;
        cin >> n >> m;
        for (int i=0;i<n;i++) cin >> a[i];
        for (int i=0;i<m;i++) cin >> b[i];
        for (int i=0;i<m;i++){
            if (b[i]<mn){
                mn=b[i];
                id=i;
            }
        }
        bool f=0;
        for (int i=0;i<n-m+1;i++){
            if (a[i]>mn){
                f=1;
            }
            if (f){
                a[i]=mn;
            }
            if (m==1) f=0;
        }
        for (int i=0;i<m;i++){
            if (a[i+n-m]>b[(id+i)%m]){
                f=1;
                break;
            }
        }
        if (f){
            for (int i=0;i<m;i++){
                a[i+n-m]=b[(id+i)%m];
            }
        }
        for (int i=0;i<n;i++) cout << a[i] << ' ';
        cout << '\n';
    }
}