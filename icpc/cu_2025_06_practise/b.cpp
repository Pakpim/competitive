#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=20,M=252;
ll dp[N][M][10][4][3][2][2], a[M][4];


int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll p[4]={2,3,5,7};
    for (ll i=1;i<M;i++){
        for (ll j=0;j<4;j++){
            ll tmp=i;
            while (tmp%p[j]==0){
                a[i][j]++;
                tmp/=p[j];
            }
        }
    }
    for (ll i=1;i<10;i++){
        dp[1][i][i][a[i][0]][a[i][1]][a[i][2]][a[i][3]] += 1+dp[1][i][i-1][a[i][0]][a[i][1]][a[i][2]][a[i][3]];
        for (int w=3;w>=0;w--){
            for (int x=2;x>=0;x--){
                for (int y=1;y>=0;y--){
                    for (int z=1;z>=0;z--){
                        if (w<a[i][0]) dp[1][i][i][w][x][y][z] += dp[1][i][i][w+1][x][y][z];
                        if (x<a[i][1]) dp[1][i][i][w][x][y][z] += dp[1][i][i][w][x+1][y][z];
                        if (y<a[i][2]) dp[1][i][i][w][x][y][z] += dp[1][i][i][w][x][y+1][z];
                        if (z<a[i][3]) dp[1][i][i][w][x][y][z] += dp[1][i][i][w][x][y][z+1];
                        dp[1][i][i+1][w][x][y][z] += dp[1][i][i][w][x][y][z];
                    }
                }
            }
        }
    }
    cout << " ? " << dp[1][1][3][0][0][0][0] << '\n';
    ll t=1;
    for (ll i=2;i<19;i++){
        t=(t*10)%M;
        for (ll j=0;j<10;j++){
            for (ll k=0;k<M;k++){
                for (ll w=3;w>=0;w--){
                    for (ll x=2;x>=0;x--){
                        for (ll y=1;y>=0;y--){
                            for (ll z=1;z>=0;z--){
                                ll xw=max(w,a[j][0]), xx=max(x,a[j][1]), xy=max(y,a[j][2]), xz=max(z,a[j][3]),xk=(k+(j*t)%M)%M;
                                dp[i][xk][j][xw][xx][xy][xz]+=dp[i-1][k][9][w][x][y][z];
                                if (j) dp[i][xk][j][xw][xx][xy][xz] += dp[i][xk][j-1][xw][xx][xy][xz];
                                if (xw<3) dp[i][xk][j][xw][xx][xy][xz] += dp[i][xk][j][xw+1][xx][xy][xz];
                                if (xx<2) dp[i][xk][j][xw][xx][xy][xz] += dp[i][xk][j][xw][xx+1][xy][xz];
                                if (xy<1) dp[i][xk][j][xw][xx][xy][xz] += dp[i][xk][j][xw][xx][xy+1][xz];
                                if (xz<1) dp[i][xk][j][xw][xx][xy][xz] += dp[i][xk][j][xw][xx][xy][xz+1];
                            }
                        }
                    }
                }
            }
        }
    }
    // for (int i=0;i<M;i++){

    // }
    ll q;
    cin >> q;
    while (q--){
        string s[2];
        ll v[2]={0,0};
        for (ll t=0;t<2;t++){
            ll m[4]={0,0,0,0}, r=1;
            cin >> s[t];
            while (s[t].size()<18) s[t]="0"+s[t];
            for (ll i=0;i<18;i++){
                r=1;
                if (s[t][i]>'0') {
                    for (ll j=0;j<M;j+=r){
                        cout << 18-i << ' ' << j << ' ' << s[t][i]-'1' << ' ' << m[0] << ' ' << m[1] << ' ' << m[2] << ' ' << m[3] << " = " << dp[18-i+1][j][s[t][j]-'1'][m[0]][m[1]][m[2]][m[3]] << '\n';
                        v[t]+=dp[18-i][j][s[t][i]-'1'][m[0]][m[1]][m[2]][m[3]];
                    }
                }
                for (ll j=0;j<4;j++) m[j]=max(m[j],a[s[t][i]-'0'][j]),r*=powl(p[j],m[j]);
            }
            for (ll j=0;j<M;j+=r){
                cout << 1 << ' ' << j << ' ' << s[t][17]-'0' << ' ' << m[0] << ' ' << m[1] << ' ' << m[2] << ' ' << m[3] << " = " << dp[1][j][s[t][17]-'0'][m[0]][m[1]][m[2]][m[3]]-dp[1][j][s[t][17]-'1'][m[0]][m[1]][m[2]][m[3]] << '\n';
                v[t]+=dp[1][j][s[t][17]-'0'][m[0]][m[1]][m[2]][m[3]]-dp[1][j][s[t][17]-'1'][m[0]][m[1]][m[2]][m[3]];
            }
        }
        cout << v[0] << ' ' << v[1] << '\n';
        cout << v[1]-v[0] << '\n';
    }
}