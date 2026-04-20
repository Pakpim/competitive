/*
I hate geo 🙉🙈
*/

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
using db=double;

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
};

struct line{
    vec p0,p1;
    line():p0(),p1(){}
    line(vec p0, vec p1): p0(p0), p1(p1){}
    bool between(vec o){
        return (o.x>=min(p0.x,p1.x) && o.x<=max(p0.x,p1.x) && o.y>=min(p0.y,p1.y) && o.y<=max(p0.y,p1.y));
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
        vec p=(p1-p0).proj(o-p0)+p0;
        if (between(p)) {
            return p.dist(o);
        }
        else return min({p0.dist(o), p1.dist(o)});
    }
};

struct poly{
    vector<vec> v; // points
    db area(){
        db re=0;
        for (int i=0;i<v.size();i++){
            int xi=(i+1)%v.size();
            re+=v[i].cross(v[xi]);
        }
        return re/2.0;
    }
    void add(vec o){
        v.emplace_back(o);
    }
};

signed main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    poly p;
    while (n--){
        db a,b;
        cin >> a >> b;
        p.add(vec(a,b));
    }
    cout << fixed << setprecision(1) << p.area() << '\n';
}