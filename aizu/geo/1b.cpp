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
    db sqdist (vec o){
        return (x - o.x)*(x - o.x) + (y - o.y)*(y - o.y);
    }
    db dot(vec o){
        return x*o.x+y*o.y;
    }
    db abs(){
        return sqrt(dot(*this));
    }
    db angle(vec o) {
        return acos(this->dot(o) / this->abs() / o.abs());
    }
    vec proj(vec o){
        return vec(*this)*(dot(o)/dot(*this));
    }
};

signed main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll x1,y1,x2,y2,p;
    cin >> x1 >> y1 >> x2 >> y2 >> p;
    vec a(x1,y1), b(x2,y2), l=b-a;
    while (p--){
        ll xi, yi;
        cin >> xi >> yi;
        vec c(xi,yi), d=c-a;
        vec p = l.proj(d) + a;
        p=p*2.0 -c;
        cout << fixed << setprecision(10) << p.x << ' ' << p.y << '\n';
    }
}

/*
7 0 0 0
1
23 39
*/