#include <bits/stdc++.h>
#define mid (l+r)/2
using namespace std;

using vvd=vector<vector<deque<int>>>;
const int N=1e5+5,inf=1e9;
int a[N],b[N];
int n,k;
mt19937 rnd;

void cal (vvd &re,int l=1,int r=n-1){
    for (int i=0;i<2;i++){
        vector<deque<int>> tmp;
        for (int j=0;j<2;j++){
            deque<int> tmp2;
            tmp.emplace_back(tmp2);
        }
        re.emplace_back(tmp);
    }
    if (l>r) return;
    if (l==r){
        re[0][0].emplace_back(b[l]);
        return;
    }
    vvd da,db;
    cal(da,l,mid),cal(db,mid+1,r);
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            deque<int> dq;
            dq.emplace_back(0);
            for (int t=0;t<2;t++){
                int ns=0,cnt=0,pa=0,pb=0;
                while (cnt<k && (pa<da[i][t].size() || pb<db[1-t][j].size())){
                    int nv;
                    if (pa>=da[i][t].size()) nv=db[1-t][j][pb++];
                    else if (pb>=db[1-t][j].size() || da[i][t][pa]<db[1-t][j][pb]) nv=da[i][t][pa++];
                    else nv=db[1-t][j][pb++];
                    cnt++;
                    ns+=nv;
                    if (cnt>=dq.size()) dq.emplace_back(ns);
                    else dq[cnt]=min(dq[cnt],ns);
                }
            }
            for (int t=1;t<dq.size();t++) re[i][j].emplace_back(dq[t]-dq[t-1]);
        }
    }
    // cout << l << ' ' << r << " => ";
    // for (auto e:re[0][0]) cout << e << ' ';
    // cout << '\n';
}

int solve (){
    for (int i=1;i<n;i++) b[i]=a[i]-a[i-1];
    vvd v;
    cal(v);
    int re=0;
    for (auto e:v[0][0]) re+=e;
    return re;
}

int solve2(){
    for (int i=1;i<n;i++) b[i]=a[i]-a[i-1];
    int dp[k+5][n+5];
    for (int i=1;i<=k;i++) for (int j=0;j<=n;j++) dp[i][j]=inf;
    for (int i=0;i<=n;i++) dp[0][i]=0;
    dp[1][1]=b[1];
    for (int i=1;i<=k;i++){
        for (int j=2;j<n;j++){
            dp[i][j]=min(dp[i][j-1],dp[i-1][j-2]+b[j]);
            // cout << i << ' ' << j << " => " << dp[i][j] << ' ' << b[j] << '\n';
        }
    }
    return dp[k][n-1];
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    bool test=0;
    if (!test){
        cin >> n >> k;
        for (int i=0;i<n;i++) cin >> a[i];
        cout << solve();
    }
    else{
        int t=1000;
        while (t--){
            n=max(2,int(rnd()%20));
            k=(rnd()%(n/2))+1;
            for (int i=0;i<n;i++) a[i]=rnd()%(int(30));
            sort(a,a+n);
            int a1=solve(),a2=solve2();
            if (a1!=a2){
                cout << n << ' ' << k << '\n';
                for (int i=0;i<n;i++) cout << a[i] << ' ';
                cout << "\n = " << a1 << ' ' << a2 << '\n';
                break;
            }
        }
    }
}

/*
11 4
2 4 4 5 8 14 18 23 23 26 29 
 = 5 6
*/