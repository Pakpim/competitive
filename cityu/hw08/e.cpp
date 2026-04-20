#include <bits/stdc++.h>
using namespace std;

const int N=1e6+5, P=1e3+5;
int sum[N], fcnt[N], xov=0, ch[N][30], cnt[N], npt=1;
bool f[N];
vector<int> prime;
vector<pair<int,int>> pf[N];

int bp(int a,int b){
    int re=1;
    for (;b;b>>=1, a*=a) if (b&1) re*=a;
    return re; 
}

signed main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i=2;i<P;i++){
        if (f[i]) continue;
        prime.emplace_back(i);
        for (int j=i*i;j<P;j+=i) {
            f[j]=1;
        }
    }
    for (int i=1;i<N;i++){
        fcnt[i]=1;
        int ni=i;
        for (auto e:prime){
            int cnt=0;
            while (ni%e==0){
                cnt++;
                ni/=e;
            }
            if (!cnt) continue;
            fcnt[i]*=(cnt+1);
            pf[i].emplace_back(e,cnt+1);
        }
        if (ni>1){
            fcnt[i]*=2;
            pf[i].emplace_back(ni,2);
        }
        for (int j=0;j<fcnt[i];j++){
            int nf=1, nj=j;
            for (auto [np,cnt]:pf[i]){
                nf *= bp(np, nj%cnt);
                nj/=cnt;
            }
        }
    }
    while (n--){
        string s;
        cin >> s;
        int nn=0;
        for (auto e:s){
            if (!ch[nn][e-'a']) ch[nn][e-'a'] = npt++;
            nn=ch[nn][e-'a'];
            cnt[nn]++;
            int nv=cnt[nn];
            for (int j=0;j<fcnt[nv];j++){
                int nf=1, nj=j;
                for (auto [np,ncnt]:pf[nv]){
                    nf *= bp(np, nj%ncnt);
                    nj/=ncnt;
                }
                xov ^= sum[nf]*nf;
                sum[nf]++;
                xov ^= sum[nf]*nf;
            }
        }
        cout << xov << ' ';
    }
}