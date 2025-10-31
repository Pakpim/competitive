#include <iostream>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n,cnt1=0,cnt2=0,v1=0,v2=0;
        bool ok=1;
        cin >> n;
        for (int i=0;i<n;i++){
            int a;
            cin >> a;
            if (!v1) v1=a,cnt1++;
            else if (v1==a) cnt1++;
            else if (!v2) v2=a,cnt2++;
            else if (v2==a) cnt2++;
            else ok=0;
        }
        if (cnt2>cnt1) swap(cnt1,cnt2);
        if (ok && (!cnt1 || !cnt2 || cnt1-cnt2==0 || cnt1-cnt2==1)){
            cout << "Yes\n";
        }
        else cout << "No\n";
    }
}