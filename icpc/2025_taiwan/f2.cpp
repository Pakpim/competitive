#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=1<<20;
ll dp[N],pc[N],br[4],bc[4];
bool f[N],f2[N];
string s[4];
char c[5]={'G','L','M','S','X'};
map<char,ll> mp = {{'G',0},{'L',1},{'M',2},{'S',3},{'X',4}};
map<ll, ll> m2;

ll hs (vector<string> &v){
    ll re=0;
    for (ll i=0,t=1;i<16;i++,t*=10) re+=mp[v[i/4][i%4]]*t;
    return re;
}

ll dfs2(vector<string> &st, ll ts, vector<ll> &tbr, vector<ll> &tbc, int nn){
    if (m2.count(ts)) {
        return m2[ts];
    }
    bool fg=1;
    for (ll i=0;i<4;i++) fg&=(tbr[i]==15 && tbc[i]==15);
    if (fg) {
        return m2[ts]=1;
    }
    int nr=nn/4, nc=nn%4;
    // int nv = ts/powl(10,nn);
    // nv%=10;
    if (st[nr][nc]){
        return m2[ts]=dfs2(st,ts,tbr,tbc,nn+1);
    }
    ll re=0;
    bool ok=0;
    for (ll i=0;i<4;i++){
        if (((tbr[nr]>>i)&1)==0 && ((tbc[nc]>>i)&1)==0){
            st[nr][nc]=c[i];
            tbr[nr]^=1<<i;
            tbc[nc]^=1<<i;
            ok=1;
            ll tmp=dfs2(st,ts,tbr,tbc, nn+1);
            re+=tmp;
            re=min(2ll,re);
            tbr[nr]^=1<<i;
            tbc[nc]^=1<<i;
            st[nr][nc]='X';
            if (re==2) {
                return m2[ts]=re;
            }
        }
    }
    if (!ok) {
        return m2[ts]=0;
    }
    return m2[ts]=re;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while (t--){
        memset(dp, 0 , sizeof(dp));
        memset( f, 0 , sizeof( f));
        memset(pc, 0 , sizeof(pc));
        memset(f2, 0 , sizeof(f2));
        memset(br, 0 , sizeof(br));
        memset(bc, 0 , sizeof(bc));
        ll a=0;
        ll cnt =0;
        for (ll i=0;i<4;i++) {
            cin >> s[i];
            for (ll j=0;j<4;j++){
                if (s[i][j]=='X') a|=1<<(i*4+j),cnt++;
                else br[i]|=1<<mp[s[i][j]], bc[j]|=1<<mp[s[i][j]];
            }
        }
        for (ll i=(1<<16)-1;i>=a;i--){
            vector<string> ts(4,"XXXX");
            vector<ll> tbc(4,0), tbr(4,0);
            for (ll j=0;j<4;j++){
                for (ll k=0;k<4;k++) {
                    if (i>>(j*4+k)&1) continue;
                    ts[j][k]=s[j][k];
                    tbr[j]|=1<<mp[s[j][k]];
                    tbc[k]|=1<<mp[s[j][k]];
                }
            }
            ll tmp=dfs2(ts, hs(ts),tbr,tbc,0);
            // bool tmp=fill(ts);
            if (tmp>1){
                dp[i]=-1;
                continue;
            }
            
            ll mn=1e9, mx=-1;
            for (ll j=0;j<16;j++) if (!(i>>j&1)){
                ll xb=i|1<<j;
                ll nv=dp[xb];
                if (dp[xb]==-1) continue;
                if (nv&1){
                    mn=min(mn,nv);
                }
                else{
                    mx=max(mx,nv);
                }
            }
            if (mx!=-1) dp[i]=mx+1;
            else if (mn!=1e9) dp[i]=mn+1;
            else dp[i]=0;
        }
        ll nv=dp[a];
        cout << 16-nv-cnt << '\n';
    }
}

/*
1
XXXX
XXXX
XXXX
XXXG

1
GLMS
LSGM
MGXL
SMLG

1
XXXX
XXXX
MXXX
SMLG

1
GLMS
LMSG
MSXL
SGLM

10
SLGM
MGSL
LSMG
GMLS
LMSG
GSML
MGLS
SLGM
SGML
LMGS
MSLG
GLSM
SLMG
LMGS
GSLM
MGSL
LGMS
MSLG
GLSM
SMGL
SGML
GSLM
LMGS
MLSG
LSMG
SGLM
MLGS
GMSL
SLGM
MGSL
GMLS
LSMG
GSML
SLGM
MGLS
LMSG
GMLS
MGSL
LSMG
SLGM
*/