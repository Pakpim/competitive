/*
I hate geo 🙉🙈
*/

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
using db=double;

struct vec{
    // vector size 2
    ll x,y;
    vec(): x(0), y(0) {}
    vec(ll x, ll y): x(x), y(y) {}
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
    vec operator/=(const ll o){
        x/=o; y/=o;
        return *this;
    }
    vec operator+(const vec o) const {
        return vec(*this) += o;
    }
    vec operator-(const vec o) const {
        return vec(*this) -= o;
    }
    vec operator*(const ll o) const {
        return vec(*this) *= o;
    }
    vec operator/(const ll o) const {
        return vec(*this) /= o;
    }
    ll dot(vec o){
        return x*o.x+y*o.y;
    }
    ll cross(vec o){
        return x*o.y - y*o.x;
    }
    vec proj(vec o){
        return vec(*this)*(dot(o)/dot(*this));
    }
    
};

signed main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll q;
    cin >> q;
    while (q--){
        ll x0,y0,x1,y1,x2,y2,x3,y3;
        cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        vec p0(x0,y0), p1(x1,y1), p2(x2,y2), p3(x3,y3);
        vec l1=p1-p0, l2=p3-p2;
        if (l1.dot(l2)==0) cout << "1\n"; // orthogonal
        else if (l1.cross(l2)==0) cout << "2\n"; // parallel
        else cout << "0\n";
    }
}