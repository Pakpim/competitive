#include <bits/stdc++.h>
using namespace std;

int main (){
    // ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        int sum=0,c=0,k=0;
        cin >> n;
        set<int>s;
        vector<int> u(n+1,0), v(n+1,0);
        for (int i=0;i<=n;i++){
            s.emplace(i);
            cin >> u[i] >> v[i];
            sum^=(u[i]&1);
            sum^=(v[i]&1);
        }
        s.erase(0);
        if (sum&1){
            cout << "First\n";
            cout.flush();
            for (int i=0;i<n;i++){
                if (i%2==0){
                    auto a=*(s.begin());
                    cout << a << '\n';
                    cout.flush();
                    s.erase(a);
                }
                else{
                    int a;
                    cin >> a;
                    s.erase(a);
                }
            }
        }
        else{
            cout << "Second\n";
            cout.flush();
            for (int i=0;i<n;i++){
                if (i%2==1){
                    auto a=*(s.begin());
                    cout << a << '\n';
                    cout.flush();
                    s.erase(a);
                }
                else{
                    int a;
                    cin >> a;
                    s.erase(a);
                }
            }
        }
    }
}