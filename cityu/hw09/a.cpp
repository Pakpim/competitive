#include <bits/stdc++.h>
using namespace std;

using ll=long long;

struct vec{
    ll x,y;
    vec(): x(0), y(0){}
    vec(ll x,ll y): x(x), y(y){}
    vec operator+=(const vec o){
        x+=o.x; y+=o.y;
        return *this;
    }
    vec operator-=(const vec o){
        x-=o.x; y-=o.y;
        return *this;
    }
    vec operator*=(const ll o){
        x*=o; y*=o;
        return *this;
    }
    vec operator+ (const vec o){
        return vec(*this) += o;
    }
    vec operator- (const vec o){
        return vec(*this) -= o;
    }
    vec operator* (const ll o){
        return vec(*this) *= o;
    }
    ll dot(vec o) const{
        return x*o.x + y*o.y;
    }
    ll cross(vec o) const{
        return x*o.y - y*o.x;
    }
    ll dist(vec o) const{
        vec tmp(*this);
        return (tmp-o).dot(tmp-o);
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

const int N=505;
ll h[N];
vec p[N];

signed main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> p[i].x >> p[i].y >> h[i];
    }
    for (int i=0;i<n;i++){
        ll mn=h[i]*h[i];
        for (int j=0;j<n;j++){
            if (h[j]<=h[i]) continue;
            mn=min(mn,p[i].dist(p[j]));
        }
        // cout << " ? " << mn << "  : ";
        cout << ll(sqrtl(mn)) << '\n';
    }
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