#include <map>
#include <iostream>
using namespace std;
using ll=long long;
int mn1,mn2;
string s[10];
int bl[7][7]={{0,0,0,0,0,0,0},
              {0,0,1,1,1,0,0},
              {0,1,1,1,1,1,0},
              {0,1,1,1,1,1,0},
              {0,1,1,1,1,1,0},
              {0,0,1,1,1,0,0},
              {0,0,0,0,0,0,0}};

bool ch (int nr,int nc){
    return (s[nr][nc]=='B' && s[nr-1][nc-1]=='B' && s[nr-1][nc+1]=='B' && s[nr+1][nc-1]=='B' && s[nr+1][nc+1]=='B');
}

void dfs1(int nr,int nc,int cnt){
    // if (cnt>4 || cnt>mn1) return;
    if (nr==7){
        // for (int i=0;i<7;i++) cout << " => " << s[i] <<  '\n';
        // cout << '\n';
        for (int i=1;i<6;i++){
            for (int j=1;j<6;j++){
                if ((i^j)&1) continue;
                if (ch(i,j)) return;
            }
        }
        mn1=min(mn1,cnt);
        return;
    }
    int xr=nr,xc=nc+2;
    if (xc>6) xr++,xc=0+(xr&1);
    dfs1(xr,xc,cnt);
    if (bl[nr][nc] && s[nr][nc]=='B'){
        s[nr][nc]='W';
        dfs1(xr,xc,cnt+1);
        s[nr][nc]='B';
    }
    return;
}

void dfs2(int nr,int nc,int cnt){
    // if (cnt>4 || cnt>mn2) return;
    if (nr==7){
        for (int i=1;i<6;i++){
            for (int j=1;j<6;j++){
                if (ch(i,j) && (i^j)&1) return;
            }
        }
        mn2=min(mn2,cnt);
        return;
    }
    int xr=nr,xc=nc+2;
    if (xc>6) xr++,xc=1-(xr&1);
    dfs2(xr,xc,cnt);
    if (bl[nr][nc] && s[nr][nc]=='B'){
        s[nr][nc]='W';
        dfs2(xr,xc,cnt+1);
        s[nr][nc]='B';
    }
    return;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        mn1=mn2=1e9;
        for (int i=0;i<7;i++) cin >> s[i];
        dfs1(0,0,0);
        dfs2(0,1,0);
        cout << mn1+mn2 << '\n';
    }
}
