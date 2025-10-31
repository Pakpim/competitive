#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=1005;
ll a[N][N],sr[N],sc[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n,m;
        string s;
        cin >> n >> m >> s;
        for (int i=0;i<n;i++) sr[i]=0;
        for (int i=0;i<m;i++) sc[i]=0;
        for (int i=0;i<n;i++) for (int j=0;j<m;j++) cin >> a[i][j];
        for (int i=0;i<n;i++) for (int j=0;j<m;j++) sr[i]+=a[i][j],sc[j]+=a[i][j];
        int nr=0,nc=0;
        for (int i=0;i<s.size();i++){
            if (s[i]!='R'){
                a[nr][nc]=-sr[nr];
            }
            else{
                a[nr][nc]=-sc[nc];
            }
            sr[nr]+=a[nr][nc];
            sc[nc]+=a[nr][nc];
            if (s[i]=='R') nc++;
            else nr++;
        }
        a[nr][nc]=-sr[nr];
        sr[nr]+=a[nr][nc];
            sc[nc]+=a[nr][nc];
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++) cout << a[i][j] << ' ';
            cout << '\n';
        }
    }
}