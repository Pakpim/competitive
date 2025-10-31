#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    long long t;
    cin >> t;
    while (t--){
        long long sl,sr,k;
        cin >> sl >> sr >> k;
        long long l=sl,r=sr,mid,ans=sl-1;
        while (l<=r){
            mid=(l+r)/2;
            if (mid*k<=sr){
                l=mid+1;
                ans=max(ans,mid);
            }
            else r=mid-1;
        }
        cout << ans - sl +1 << '\n';
    }
}