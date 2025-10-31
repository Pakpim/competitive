#include <bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int a[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n,k,tg,ans=0,np=0;
        cin >> n >> k >> tg;
        k*=2;
        tg*=2;
        for (int i=0;i<n;i++) cin >> a[i],a[i]*=2;
        ans=a[0];
        np=k;
        for (int i=1;i<n;i++){
            if (np>=a[i]+ans) np=a[i]+ans+k;
            else{
                if (np>=a[i]-ans) np+=k;
                else {
                    int xp=(a[i]-ans+np)/2+k;
                    ans+=(a[i]-ans-np)/2;
                    np=xp;
                }
            }
            // cout << " => " << i << ' ' << np << ' ' << ans << '\n';
        }
        if (np<tg) ans+=tg-np;
        cout << ans << '\n';
    }
}