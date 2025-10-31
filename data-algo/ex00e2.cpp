// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,q,st[105][105][7][7];
    bool db=0;
    scanf("%d%d%d",&n,&m,&q);
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) scanf("%d",&st[i][j][0][0]) ;
    for (int i=1;1<<i<n;i++){
        for (int r=1;r<=n;r++){
            for (int c=1;c<=m;c++){
                int mr=min(n,r+(1<<(i-1)));
                st[r][c][i][0]=max(st[r][c][i-1][0],st[mr][c][i-1][0]);
            }
        }
    }
    for (int i=1;1<<i<m;i++){
        for (int r=1;r<=n;r++){
            for (int c=1;c<=m;c++){
                int mc=min(m,c+(1<<(i-1)));
                st[r][c][0][i]=max(st[r][c][0][i-1],st[r][mc][0][i-1]);
            }
        }
    }
    for (int i=1;1<<i<n;i++){
        for (int j=1;1<<j<m;j++){
            for (int r=1;r<=n;r++){
                for (int c=1;c<=m;c++){
                    int mr=min(n,r+(1<<(i-1))),mc=min(m,c+(1<<(j-1)));
                    st[r][c][i][j]=max({st[r][c][i-1][j-1],
                                        st[mr][c][i-1][j-1],
                                        st[r][mc][i-1][j-1],
                                        st[mr][mc][i-1][j-1]});
                }
            }
        }
    }
    while (q--){
        int r1,c1,r2,c2;
        scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
        if (r1>r2 || c1>c2){
            printf("INVALID\n");
            continue;
        }
        if (r1>n || c1>m){
            printf("OUTSIDE\n");
            continue;
        }
        r1=max(r1,1); c1=max(c1,1);
        r2=min(r2,n); c2=min(c2,m);
        int i=log2(r2-r1+1),j=log2(c2-c1+1);
        printf("%d\n",max({st[r1][c1][i][j],
                           st[r2-(1<<i)+1][c1][i][j],
                           st[r1][c2-(1<<j)+1][i][j],
                           st[r2-(1<<i)+1][c2-(1<<j)+1][i][j]}));
        // int mx=-1e9;
        // for (int i=r1;i<=r2;i++) for (int j=c1;j<=c2;j++) mx=max(mx,st[i][j][0][0]);
        // printf("%d\n",mx);
    }
}