#include <bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int a[N],cnt[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        int l=1,mx=0;
        int al=0,ar=0;
        cin >> n;
        for (int i=1;i<=n;i++) cnt[i]=0;
        for (int i=1;i<=n;i++){
            cin >> a[i];
            cnt[a[i]]++;
        }
        for (int i=1;i<=n;i++){
            if (cnt[a[i]]==1){
                if (mx<i-l+1){
                    mx=i-l+1;
                    ar=i;
                    al=l;
                }
            }
            else{
                l=i+1;
            }
        }
        if (mx==0) cout << "0\n";
        else cout << al << ' ' << ar << '\n';
    }
}