#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using db=double;

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
        x+=o; y+=o;
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
        return x*o.y-y*o.x;
    }
    bool operator==(const vec o) const {
        return ((x==o.x) && (y==o.y));
    }
    bool operator<(const vec &o) const {
        if (y>=0 && o.y<0) return 1;
        if (y<0 && o.y>=0) return 0;
        if (x*(y>=0)>=0 && o.x*(o.y>=0)<0) return 1;
        if (x*(y>=0)<0 && o.x*(o.y>=0)>=0) return 0;
        if (cross(o)==0) return dot(*this)<o.dot(o);
        return cross(o)>0;
    }
};

deque<vec> hull(deque<vec> v){
    deque<vec> re;
    for (int i=0;i<v.size();i++){
        while (re.size()>1){
            vec v1=re[re.size()-2], v2=re.back(), v3=v[i];
            if ((v2-v1).cross(v3-v2)<=0) re.pop_back();
            else break;
        }
        if (re.empty() || !(v[i]==re.back())) re.emplace_back(v[i]);
    }
    return re;
}

void solve(int n){
    deque<vec> v;
    deque<pair<vec,vec>> pv;
    vec mn(1e18,1e18);
    for (int i=0;i<n;i++){
        ll a,b;
        cin >> a >> b;
        v.emplace_back(a,b);
        if (b<mn.y || (b==mn.y && a<mn.x)) mn=v[i];
    }
    for (int i=0;i<n;i++){
        pv.emplace_back(v[i]-mn, v[i]);
    }
    sort(pv.begin(),pv.end());
    v.clear();
    for (auto [fv,sv]:pv) {
        v.emplace_back(sv);
    }
    deque<vec> h = hull(v);
    cout << h.size() << '\n';
    for (auto e:h) cout << e.x << ' ' << e.y << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    while (cin >> n){
        if (n==0) exit(0);
        solve(n);
    }
}