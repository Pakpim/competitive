#include <iostream>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        bool b=0;
        string s[20];
        cin >> n;
        // cout << " => " << n << '\n';
        for (int i=0;i<n;i++) cin >> s[i];
        for (int i=1;i<n;i++){
            for (int j=1;j<n;j++){
                if (s[i][j]=='1' && s[i-1][j]=='1' && s[i-1][j-1]=='1' && s[i][j-1]=='0') b=1;
                if (s[i][j]=='1' && s[i-1][j]=='1' && s[i-1][j-1]=='0' && s[i][j-1]=='1') b=1;
            }
        }
        // for (int i=0;i<n;i++) cout << " => " << s[i] << '\n';
        if (b) cout << "TRIANGLE\n";
        else cout << "SQUARE\n";
    }
}