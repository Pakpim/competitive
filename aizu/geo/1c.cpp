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
    ll x1,y1,x2,y2,p;
    cin >> x1 >> y1 >> x2 >> y2 >> p;
    vec a(x1,y1), b(x2,y2), l=b-a;
    while (p--){
        ll xi, yi;
        cin >> xi >> yi;
        vec c(xi,yi);
        vec v1=b-a, v2=c-a;
        ll cross = v1.cross(v2);
        if (cross>0) cout << "COUNTER_CLOCKWISE";
        else if (cross<0) cout << "CLOCKWISE";
        else{
            vec v3=a-b, v4=c-b;
            ll dot1=v1.dot(v2), dot2=v3.dot(v4);
            if (dot1<0) cout << "ONLINE_BACK";
            else if (dot2<0) cout << "ONLINE_FRONT";
            else cout << "ON_SEGMENT";
        }
        cout << '\n';
    }
}