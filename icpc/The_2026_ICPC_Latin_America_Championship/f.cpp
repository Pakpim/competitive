#include <bits/stdc++.h>
using namespace std;

const int N=155,R=18;
int a[N],par[N],sz[N], t[R+5][R*2+5], mx, ans;

int root(int nn){
    if (!par[nn]) return nn;
    return par[nn]=root(par[nn]);
}

void uni(int u,int v){
    // cout << " ! " << u << ' ' << v << " = ";
    u=root(u); v=root(v);
    if (u==v) return;
    if (sz[u]>sz[v]) swap(u,v);
    par[u]=v;
    sz[v]+=sz[u];
    mx=max(mx,sz[v]);
    // cout << v << ' ' << sz[v] << '\n';
    return;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=0;i<1<<R;i++){
        for (int j=1;j<=n;j++) par[j]=0, sz[j]=1;
        for (int j=0;j<=R;j++) for (int k=0;k<R*2+5;k++) t[j][k]=0;
        mx=1;
        int ch=0, b=0, py=0, px=R+1, dir=0, mnx=px, mxx=px;
        // cout << " ? " << bitset<4>(i) << '\n';
        for (int j=1;j<=n;j++){
            // cout << " --> " << ch << ' ' << dir << ' ' << py << ' ' << px << '\n';
            if (ch){
                if (i>>b&1){ // '|'
                    py=0, px=mnx-1, dir=1, mnx--;
                }
                else{ // '\'
                    py=0, px=mxx+1, dir=0, mxx++;
                }
                b++;
                ch=0;
            }
            t[py][px]=j;
            for (int k=0;k<2;k++){
                if (py && a[t[py-1][px+k]]==a[t[py][px]]) uni(t[py-1][px+k],t[py][px]);
            }
            for (int k=-1;k<2;k+=2){
                if (t[py][px+k] && a[t[py][px+k]]==a[t[py][px]]) uni(t[py][px+k], t[py][px]);
            }
            if (dir) {
                py++; // '|'
                if (!t[py-1][px+1]) ch=1;
            }
            else{
                py++, px--; // '\'
                if (!t[py-1][px]) ch=1;
            }
        }
        // for (int j=R;j>=0;j--) {
        //     for (int k=0;k<=2*R+1;k++) cout << t[j][k] << ' '; 
        //     cout << '\n';
        // }
        // cout << " = " << mx << '\n';
        ans=max(ans,mx);
    }
    cout << ans;
}

/*
13
1 2 1 2 2 1 3 1 1 1 3 3 2
*/