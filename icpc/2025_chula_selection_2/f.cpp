#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using tll = tuple<ll,ll,ll,ll,ll>;

ll solve (ll a,ll b,ll c,ll d,ll x,ll y){
    ll t[4]={a,b,c,d};
    ll bx,by;
    bx=x, by=y;
    if ((x<0 && y>=0 && y<=-x) || (x>=0 && y<0 && x>-y)){
        a=t[0]; b=t[2]; c=t[3]; d=t[1];
        x=by; y=-by-bx;
    }
    else if ((x<0 && y>=0 && y>-x) || (x>=0 && y<0 && x<=-y)){
        a=t[0]; b=t[3]; c=t[1]; d=t[2];
        x=-by-bx; y=bx;
    }
    else{
        a=t[0]; b=t[1]; c=t[2]; d=t[3];
    }
    bx=x, by=y;
    if (x<0) x=-x;
    if (y<0) y=-y;
    ll sum = b*((y>>1ll) + (y&1ll)) + d*(((y>>1ll))+(y&1ll)) + c*((y>>1ll)) + a*((y>>1ll));
    // cout << sum << '\n';
    if (by>0 || (by==0 && bx>0)) sum+=c;
    if (y&1ll){
        sum+=b*(x>>1ll) + d*(x>>1ll) + c*((x>>1ll) + (x&1ll)) + a*((x>>1ll) + (x&1ll));
        // cout << sum << '\n';
        if (bx>0){
            if (x&1ll) sum-=a;
            else sum-=b;
        }
        if (by<0 && bx>0) sum-=d;
        if (by>0 && bx<=0) sum-=b;
    }
    else{
        sum+=c*(x>>1ll) + a*(x>>1ll) + b*((x>>1ll) + (x&1ll)) + d*((x>>1ll) + (x&1ll));
        // cout << sum << '\n';
        if (bx>0){
            if (x&1ll) sum-=d;
            else sum-=c;
        }
        // cout << sum << '\n';
        if (by<0 && bx>0) sum-=a;
        if (by>0 && bx<=0) sum-=c;
        // cout << sum << '\n';
    }
    // cout << bx << ' ' << by << " = ";
    return sum;
}

ll dist[3005][3005][2];
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t=1;
    while (t--){
        ll a,b,c,d,x,y;
        cin >> a >> b >> c >> d >> x >> y;
        cout << solve(a,b,c,d,x,y) << '\n';
    }
    // ll v[4]={1,10,100,1000};
    // ll v[4]={1000000,1000000,1000000,1000000};
    // ll a[4][3]={{1,2,3},{0,3,2},{3,0,1},{2,1,0}}, d[3][2]={{0,-1},{0,0},{-1,0}};
    // ll R=1500;
    // for (int i=-1500;i<=1500;i++) for (int j=-1500;j<=1500;j++) dist[i+R][j+R][0]=dist[i+R][j+R][1]=1e18;
    // priority_queue<tll,vector<tll>,greater<tll>> pq;
    // pq.emplace(0,0,0,0,0);
    // while (!pq.empty()){
    //     auto [nd,nx,ny,ns,nb]=pq.top(); pq.pop();
    //     if (dist[nx+R][ny+R][ns]<=nd) continue;
    //     // cout << nx+R << ' ' << ny+R << ' ' << ns << ' ' << dist[1000][1000][0] << '\n';
    //     dist[nx+R][ny+R][ns]=nd;
    //     if (ns==0){
    //         ll nv=solve(v[0],v[1],v[2],v[3],nx,ny);
    //         if (nv!=nd){
    //             cout << nx << ' ' << ny << ' ' << nv << ' ' << nd << '\n';
    //             return 0;
    //         }
    //     }
    //     for (int i=0;i<3;i++){
    //         ll xx=nx+d[i][0]*(ns? -1:1);
    //         ll xy=ny+d[i][1]*(ns? -1:1);
    //         if (xx<-1500 || xx>1500 || xy<-1500 || xy>1500) continue;
    //         pq.emplace(nd+v[a[nb][i]],xx,xy,ns^1,a[nb][i]);
    //     }
    // }
}