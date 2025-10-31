#include <bits/stdc++.h>
using namespace std;

const int N=3005;
int dp[N][N],t[N];
char h[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,q;
    cin >> n >> q;
    for (int i=0;i<=q;i++) for (int j=0;j<n;j++) {
        dp[i][j]=1e9;
    }
    h[0]='L';
    t[0]=0;
    dp[0][1]=0;
    for (int i=1;i<=q;i++){
        cin >> h[i] >> t[i];
        t[i]--;
        for (int j=0;j<n;j++){
            if (dp[i-1][j]==1e9 || t[i-1]==j) continue;
            int nl,nr,mh,oh;
            if (h[i-1]=='L') nl=t[i-1],nr=j;
            else nr=t[i-1], nl=j;
            if (h[i]=='L') mh=nl,oh=nr;
            else mh=nr,oh=nl;
            if ((t[i]-mh+n)%n < (oh-mh+n)%n) dp[i][oh]=min(dp[i][oh],dp[i-1][j]+(t[i]-mh+n)%n);
            if ((t[i]-mh+n)%n > (oh-mh+n)%n) dp[i][oh]=min(dp[i][oh],dp[i-1][j]+(mh-t[i]+n)%n);
            if ((t[i]-mh+n)%n <= (oh-mh+n)%n) dp[i][(t[i]-1+n)%n]=min(dp[i][(t[i]-1+n)%n],dp[i-1][j]+(mh-t[i]+n)%n+(oh-((t[i]-1+n)%n)+n)%n);
            if ((t[i]-mh+n)%n >= (oh-mh+n)%n) dp[i][(t[i]+1)%n]=min(dp[i][(t[i]+1)%n],dp[i-1][j]+(t[i]-mh+n)%n+(((t[i]+1)%n)-oh+n)%n);
        }
    }
    int mn=1e9;
    for (int i=0;i<n;i++) mn=min(mn,dp[q][i]);
    cout << mn;
}