#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=305;
bool dp[N][N][N][2];
vector<int> par[N][N][N][2];
set<pair<char,int>> s[3];
char o[N];
int v[N],a[3],x;

void play (int i){
    auto it=s[i].begin();
    cout << it->first << ' ' << it-> second << '\n';
    cout.flush();
    s[i].erase(it);
    a[i]--;
}

void rm (char nc,int nv){
    if (nc=='+' && nv&1) x^=1,s[1].erase({nc,nv}),a[1]--;
    else if (nc=='*' && (nv&1)==0) x=0,s[2].erase({nc,nv}),a[2]--;
    else s[0].erase({nc,nv}),a[0]--;
}

int main (){
    // ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> o[i] >> v[i];
        if (o[i]=='+' && v[i]&1) a[1]++,s[1].emplace(o[i],v[i]);
        else if (o[i]=='*' && (v[i]&1)==0) a[2]++,s[2].emplace(o[i],v[i]);
        else a[0]++,s[0].emplace(o[i],v[i]);
    }
    cin >> x;
    x%=2;
    dp[0][0][0][0]=(n&1);
    dp[0][0][0][1]=(n&1)^1;
    for (int i=0;i<=a[0];i++){
        for (int j=0;j<=a[1];j++){
            for (int k=0;k<=a[2];k++){
                for (int nn=0;nn<2;nn++){
                    if (i && !dp[i-1][j][k][nn]) dp[i][j][k][nn]=1,par[i][j][k][nn].emplace_back(0);
                    if (j && !dp[i][j-1][k][nn^1]) dp[i][j][k][nn]=1,par[i][j][k][nn].emplace_back(1);
                    if (k && !dp[i][j][k-1][0]) dp[i][j][k][nn]=1,par[i][j][k][nn].emplace_back(2);
                    // cout << i << ' ' << j << ' ' << k << ' ' << nn << " = " << dp[i][j][k][nn] << '\n';
                    // for (auto e:par[i][j][k][nn]) cout << e << ' ';
                    // cout << "\n";
                }
            }
        }
    }
    // cout << a[0] << ' ' << a[1] << ' ' << a[2] << ' ' << dp[a[0]][a[1]][a[2]][x];
    int t,np;
    if (dp[a[0]][a[1]][a[2]][x]){
        cout << "me\n"; cout.flush();
        t=1;
        np=1;
    }
    else {
        cout << "you\n"; cout.flush();
        t=0;
        np=0;
    }
    for (int i=0;i<n;i++,t^=1){
        if (t){
            int ni=par[a[0]][a[1]][a[2]][x].front();
            play(ni);
            if (ni==1) x^=1;
            if (ni==2) x=0;
        }
        else{
            char nc;
            int nv;
            cin >> nc >> nv;
            rm(nc,nv);
        }
        // cout << " -> " << x << ' ' << a[0] << ' ' << a[1] << ' ' << a[2] << '\n';
    }
}