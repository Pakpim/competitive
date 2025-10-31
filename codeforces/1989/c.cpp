#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int a[N],b[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n,s1=0,s2=0;
        cin >> n;
        for (int i=0;i<n;i++) cin >> a[i];
        for (int i=0;i<n;i++) cin >> b[i];
        for (int i=0;i<n;i++){
            if (a[i]!=b[i]){
                if (a[i]>b[i]) s1+=a[i];
                else s2+=b[i];
            }
        }
        for (int i=0;i<n;i++){
            if (a[i]==b[i]){
                if (a[i]==-1){
                    if (s1<s2) s2--;
                    else s1--;
                }
                if (a[i]==1){
                    if (s1<s2) s1++;
                    else s2++;
                }
            }
        }
        cout << min(s1,s2) << '\n';
    }
}