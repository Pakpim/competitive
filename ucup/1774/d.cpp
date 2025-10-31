#include <bits/stdc++.h>
using namespace std;

const int N=200005;
int ar[N];
map<int,int> mp;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n,k,m;
        cin >> n >> k >> m;
        bool f=0;
        for (int i=1;i<=n;i++) cin >> ar[i];
        sort(ar+1,ar+n+1);
        if (k&1){
            for (int i=1;i<=n;i++){
                if (i-1<k/2 || n-i<k/2) continue;
                if (ar[i]==m) f=1;
            }
        }
        else{
            for (int i=1;i<=n;i++){
                if (n-i>=(k-2)/2 && mp.find(m*2-ar[i])!=mp.end()){
                    f=1;
                }
                if (i-1>=(k-2)/2) mp[ar[i]]=1;
            }
        }
        if (f) cout << "TAK\n";
        else cout << "NIE\n";
        mp.clear();
    }
}