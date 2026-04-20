#include <bits/stdc++.h>
using namespace std;

using db=double;

struct vec{
    db x,y;
    vec(): x(0), y(0){}
    vec(db x,db y): x(x), y(y){}
    vec operator+=(const vec o){
        x+=o.x; y+=o.y;
        return *this;
    }
    vec operator-=(const vec o){
        x-=o.x; y-=o.y;
        return *this;
    }
    vec operator*=(const db o){
        x*=o; y*=o;
        return *this;
    }
    vec operator/=(const db o){
        x/=o; y/=o;
        return *this;
    }
    vec operator+ (const vec o){
        return vec(*this) += o;
    }
    vec operator- (const vec o){
        return vec(*this) -= o;
    }
    vec operator* (const db o){
        return vec(*this) *= o;
    }
    vec operator/ (const db o){
        return vec(*this) /= o;
    }
    db dot(vec o) const{
        return x*o.x + y*o.y;
    }
    db cross(vec o) const{
        return x*o.y - y*o.x;
    }
    db dist(vec o) const{
        vec tmp(*this);
        return sqrtl((tmp-o).dot(tmp-o));
    }
    vec proj(vec o){
        // cout << " ! " << this->x << ' ' << this->y << " : " << dot(o) << ' ' << dot(*this) << '\n';
        return vec(*this)*(dot(o)/dot(*this));
    }
    vec norm(){
        return vec(*this)/sqrtl(dot(*this));
    }
    bool operator==(const vec o) const {
        return ((x==o.x) && (y==o.y));
    }
    bool operator<(const vec &o) const {
        if (y>=0 && o.y<0) return 1;
        if (y<0 && o.y>=0) return 0;
        int ty=y>=0? 1:-1, oty=o.y>=0? 1:-1;
        if (x*ty>=0 && o.x*oty<0) return 1;
        if (x*ty<0 && o.x*oty>=0) return 0;
        if (cross(o)==0) return dot(*this)<o.dot(o);
        return cross(o)>0;
    }
};

const int N=1e5+5;
db r[N];
vec a[N];
pair<vec,int> p[N];
db ans[N];

signed main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,q;
    cin >> n >> m >> q;
    for (int i=0;i<n;i++) cin >> r[i];
    for (int i=0;i<m;i++){
        int fx,fy;
        cin >> fx >> fy;
        a[i]=vec(fx,fy);
    }
    for (int i=0;i<q;i++){
        int px,py;
        cin >> px >> py;
        p[i].first=vec(px,py);
        p[i].second=i;
    }
    sort(r,r+n);
    sort(a,a+m);
    sort(p,p+q);
    int pa=0;
    for (int i=0;i<q;i++){
        auto [np,ni]=p[i];
        while (a[pa]<np && np.cross(a[pa])!=0){
            pa++;
        }
        // cout << '\n' << ni << " : " << np.x << ',' << np.y << '\n';
        ans[ni]=1e18;
        for (int j=0, k=(pa-1+m)%m;j<2;j++, k=(k+1)%m){
            // cout << " ? " << k << "  : " << a[k].x << ' ' << a[k].y << '\n';
            vec pj=a[k].proj(np);
            db nd=pj.dist(vec(0,0));
            if (pj.dot(a[k])<0) nd*=-1.0;
            auto it=lower_bound(r,r+n,nd);
            // cout << "\t?? " << pj.x << ' ' << pj.y << ' ' << nd << " : " << it-r << ' ' << *it << '\n';
            if (it!=r+n){
                ans[ni]=min(ans[ni], (a[k].norm()*(*it)).dist(np));
            }
            if (it!=r){
                it--;
                ans[ni]=min(ans[ni], (a[k].norm()*(*it)).dist(np));
            }
        }
    }
    for (int i=0;i<q;i++) cout << fixed << setprecision(12) << ans[i] << '\n';
}

/*
10 2 5
1 2 3 4 5 6 7 8 9 10
0 1
-1 1
1 0
3 -3
-1 4
-3 -2
5 -8
*/