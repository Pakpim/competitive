#include <bits/stdc++.h>
using namespace std;

const int N=1005,R=100;
char c[15];
map<char,int> mp;
int xn[N][15];
char out[N][15];
int vis[N][15];
vector<char> ans;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int k,m,q;
    cin >> k >> m >> q;
    for (int i=0;i<m;i++) {
        cin >> c[i];
        mp[c[i]]=i;
    }
    for (int i=0;i<m*k;i++){
        int u;
        char in,tmp;
        cin >> u >> in;
        cin >> xn[u][mp[in]] >> out[u][mp[in]];
    }
    string s,bf[R],loop[R];
    cin >> s;
    int sz=s.size(),nn=0,np=0,nc=mp[s[np]],t=1;
    while (!vis[nn][np]){
        vis[nn][np]=t++;
        ans.emplace_back(out[nn][nc]);
        np=(np+1)%sz;
        nn=xn[nn][nc];
        nc=mp[s[np]];
    }
    int st=vis[nn][np]-1,sz2=(ans.size()-st);
    for (int i=0;i<st;i++) bf[i/R]+=ans[i];
    for (int i=st;i<ans.size();i++) loop[(i-st)/R]+=ans[i];
    while (q--){
        int l,r;
        cin >> l >> r;
        l--; r--;
        // for (int i=l;i<=r;i++) {
        //     if (i<st) cout << ans[i];
        //     else cout << ans[(i-st)%sz2+st];
        // }
        if (l<st){
            int i=l;
            while (i%R!=0 && i<=r && i<st){
                cout << c[ans[i]];
                i++;
            }
            while (i+R-1<=r && i+R-1<st){
                cout << bf[i/R];
                i+=R;
            }
            while (i<=r && i<st){
                cout << c[ans[i]];
                i++;
            }
        }
        if (r>=st){
            r-=st;
            l=max(0,l-st);
            int i=l%sz2,cnt=0;
            while (i%R!=0 && cnt+1<=r-l+1){
                cout << c[ans[i+st]];
                cnt++;
                i=(i+1)%sz2;
            }
            while (cnt+loop[i/R].size()<=r-l+1 ){
                cout << loop[i/R];
                cnt+=loop[i/R].size();
                if (loop[i/R].size()<R) i=0;
                else i+=R;
            }
            while (cnt+1<=r-l+1){
                cout << c[ans[(i)%sz2+st]];
                cnt++;
                i=(i+1)%sz2;
            }
        }
        cout << '\n';
    }
}

/*
3 3 1
0 1 #
0 0 0 0
0 1 1 1
0 # 0 #
1 0 0 1
1 1 2 #
1 # 0 1
2 0 1 0
2 1 2 #
2 # 0 0
10110101#
7 29
*/