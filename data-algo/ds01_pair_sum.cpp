#include<bits/stdc++.h>
using namespace std;

bool b[2000005];
int a[10005];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    string ans[]={"NO\n","YES\n"};
    cin >> n >> m;
    for (int i=0;i<n;i++){
        cin >> a[i];
        for (int j=0;j<i;j++) b[a[i]+a[j]]=1;
    }
    while (m--){
        int x;
        cin >> x;
        cout << ans[b[x]];
    }
}