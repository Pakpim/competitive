/*
I hate geo 🙉🙈 It's coarse and rough and irritating and it gets everywhere
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
    bool operator<(const vec o) const {
        if (y==o.y) return x<o.x;
        return y<o.y;
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
    pair<bool,db> t(db x){ // find t from p0 + t(p1-p0) = pt
        if (p0.x==p1.x) return {0,0};
        return {1,(x-p0.x)/(p1.x-p0.x)};
    }
    vec at(db t){ // find pt = p0 + t(p1-p0)
        return p0 + (p1-p0)*t;
    }
};

bool ancmp(vec a, vec b){
    if (a.cross(b)==0) return a.dot(a)<b.dot(b);
    return a.cross(b)>0;
}

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
    void add(vec o){v.emplace_back(o);}
    void pop_back(){v.pop_back();}
    int size(){return v.size();}
    vec back(){return v.back();}
    vec xback(){return v[v.size()-2];}
    bool isConvex(){
        for (int i=0;i<v.size();i++){
            int xi=i+1, bi=i-1;
            if (xi>=v.size()) xi-=v.size();
            if (bi<0) bi+=v.size();
            if ((v[i]-v[bi]).cross(v[xi]-v[i])<0) return 0;
        }
        return 1;
    }
    int isInside(vec o){ // 2 inside, 1 edge, 0 outside
        int cnt=0;
        for (int i=0;i<v.size();i++){
            int xi=i+1, bi=i-1, ci=i+2;
            if (xi>=v.size()) xi-=v.size();
            if (ci>=v.size()) ci-=v.size();
            if (bi<0) bi+=v.size();
            line l(v[i],v[xi]);
            if (l.dist(o)==0) return 1;
            auto [ns,nt]=l.t(o.x);
            if (!ns) { // |
                if (o.collinear(v[i],v[xi])) {
                    vec v0=v[bi]-v[i], v1=v[xi]-v[i], v2=v[ci]-v[xi];
                    if (max(v[i].y,v[xi].y)>o.y && v1.cross(v0)*v1.cross(v2)<=0) cnt++;
                }
            }
            else {
                if (nt<1 && nt>0 && l.at(nt).y>o.y) cnt++;
                if (nt==0 && l.at(nt).y>o.y){
                    vec v0=v[bi]-v[i], v1=v[i]-o, v2=v[xi]-v[i];
                    if (v1.cross(v0)*v1.cross(v2)<0) cnt++;
                }
            }
        }
        return ((cnt&1) ? 2:0);
    }
    poly hull(){
        poly re;
        for (int i=0;i<v.size();i++){
            while (re.size()>1){
                vec v1=re.xback(), v2=re.back(), v3=v[i];
                if ((v2-v1).cross(v3-v2)<0)re.pop_back();
                else break;
            }
            re.add(v[i]);
        }
        while (re.size()>1){
            vec v1=re.xback(), v2=re.back(), v3=v[0];
            if ((v2-v1).cross(v3-v2)<0) re.pop_back();
            else break;
        }
        return re;
    }
};

signed main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    poly p;
    vector<vec> v;
    for (int i=0;i<n;i++){
        db a,b;
        cin >> a >> b;
        v.emplace_back(a,b);
    }
    sort(v.begin(),v.end(),ancmp);
    int rev=v.size()-1; // for all edge point, rm if need min hull
    for (int i=v.size()-2;i>=0;i--){
        vec v1=v[rev], v2=v[i];
        if (v1.cross(v2)==0) rev--;
        else break;
    }
    reverse(v.begin()+rev, v.end());
    vec mn(1e9,1e9);
    int tg=-1;
    for (int i=0;i<n;i++){
        if (v[i]<mn){
            mn=v[i];
            tg=i;
        }
    }
    for (int i=0;i<n;i++){
        p.add(v[(i+tg)%n]);
    }
    poly ans=p.hull();
    cout << ans.size() << '\n';
    for (auto [x,y]:ans.v){
        cout << x << ' ' << y << '\n';
    }
}