#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double;
const db EPS = 1e-9;

struct vec{
    // vector size 2
    db x,y;
    vec(): x(0), y(0) {}
    vec(db x, db y): x(x), y(y) {}
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
    vec operator+(const vec o) const {
        return vec(*this) += o;
    }
    vec operator-(const vec o) const {
        return vec(*this) -= o;
    }
    vec operator*(const db o) const {
        return vec(*this) *= o;
    }
    vec operator/(const db o) const {
        return vec(*this) /= o;
    }
    bool operator<(const vec o) const {
        if (y==o.y) return x<o.x;
        return y<o.y;
    }
    bool operator==(const vec o) const {
        return x==o.x && y==o.y;
    }
    db dot(vec o){
        return x*o.x+y*o.y;
    }
    db cross(vec o){ // this x o
        return x*o.y - y*o.x;
    }
    vec proj(vec o){ // project o to this
        return vec(*this)*(dot(o)/dot(*this));
    }
    bool collinear(vec o1,vec o2){
        vec v1=(o1-(*this)), v2=(o2-(*this));
        return (v1).cross(v2)==0;
    }
    db dist(vec o){
        vec v=*this-o;
        return sqrt(v.dot(v));
    }
    db angle(){
        return atan2l(y,x);
    }
};

struct line{
    vec p0,p1;
    line():p0(),p1(){}
    line(vec p0, vec p1): p0(p0), p1(p1){}
    bool between(vec o){
        return (o.x>=min(p0.x,p1.x) - EPS
             && o.x<=max(p0.x,p1.x) + EPS
             && o.y>=min(p0.y,p1.y) - EPS
             && o.y<=max(p0.y,p1.y) + EPS);
    }
    pair<ll,vec> tud(line o){ // status, point
        db x0=p0.x, x1=p1.x, x2=o.p0.x, x3=o.p1.x;
        db y0=p0.y, y1=p1.y, y2=o.p0.y, y3=o.p1.y;
        db cross = (p1-p0).cross(o.p1-o.p0) * -1.0;
        if (cross==0) {
            if (p0.collinear(o.p0,o.p1)){
                if (o.between(p0)) return {1,p0};
                if (o.between(p1)) return {1,p1};
                if (between(o.p0)) return {1,o.p0};
                if (between(o.p1)) return {1,o.p1};
            }
            return {-1,vec()};
        }
        db a=((x3-x2)*(y2-y0) - (y3-y2)*(x2-x0));
        db b=((x1-x0)*(y2-y0) - (y1-y0)*(x2-x0));
        a/=cross; b/=cross;
        return {(a>=0 && a<=1 && b>=0 && b<=1),(p1-p0)*a+p0};
    }
    db dist (vec o){
        vec tmp=p1-p0;
        vec p=tmp.proj(o-p0)+p0;
        if (between(p)) {
            return p.dist(o);
        }
        else return min({p0.dist(o), p1.dist(o)});
    }
    pair<bool,db> t(db x){ // find t from p0 + t(p1-p0) = pt
        if (p0.x==p1.x) return {0,0};
        return {1,(x-p0.x)/(p1.x-p0.x)};
    }
    vec at(db t){ // find pt = p0 + t(p1-p0)
        return p0 + (p1-p0)*t;
    }
};

const int N=1e4+5;
vec p[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,q;
    cin >> n >> q;
    for (int i=0;i<n;i++) {
        db x,y;
        cin >> x >> y;
        p[i]=vec(x,y);
    }
    while(q--){
        db qx,qy;
        cin >> qx >> qy;
        vec qp(qx,qy);
        db mn=1e18;
        for (int i=1;i<n;i++){
            if (p[i-1]==p[i]) exit(1);
            line nl(p[i-1],p[i]);
            mn=min(mn,nl.dist(qp));
        }
        cout << fixed << setprecision(4) << mn << '\n';
    }
}