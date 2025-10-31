#include <bits/stdc++.h>
using namespace std;

int main (){
    int t;
    cin >> t;
    while (t--){
        int l=2,r=999,m1,m2,ans,x=1000;
        int tx,cnt=0;
        // cin >> tx;
        while (l<=r){
            m1=l+(r-l)/3;
            m2=l+(r-l)*2/3;
            cout << "? "<< m1 << ' ' << m2 << '\n';
            cout.flush();
            cin >> ans;
            // if (m1>=tx) ans=(m1+1)*(m2+1);
            // else if (m2>=tx) ans=m1*(m2+1);
            // else ans=m1*m2;
            if (ans==m1*m2){
                l=m2+1;
            }
            else if (ans==m1*(m2+1)){
                l=m1+1;
                r=m2-1;
                x=min(x,m2);
            }
            else{
                r=m1-1;
                x=min(x,m1);
            }
            // cout << " => " << ans << ' ' << l << ' ' << r << '\n';
        }
        cout << "! " << x << '\n';
        cout.flush();
    }
}