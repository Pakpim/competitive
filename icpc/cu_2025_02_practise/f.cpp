#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=1e5+5;
ll ax[N],ay[N],bx[N],by[N];
vector<tuple<ll,ll,ll>> v;
set<int> s;

struct line{
    ll x1=0,x2=0,y1=0,y2=0;
    line():x1(0),x2(0),y1(0),y2(0){}
    line(ll x1,ll x2,ll y1,ll y2):x1(x1),x2(x2),y1(y1),y2(y2){}
    bool tud_up (ll xn,ll yn){
        // cout << " -> " << (y2-y1) << ' ' << (xn-x1) << ' ' << (yn-y1) << ' ' << (x2-x1) << '\n';
        return (y2-y1)*(xn-x1)>(yn-y1)*(x2-x1);
    }
    bool tud_down (ll xn,ll yn){
        return (y2-y1)*(xn-x1)<(yn-y1)*(x2-x1);
    }
} l[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,m;
    cin >> n;
    for (ll i=0;i<n;i++){
        cin >> ax[i] >> ay[i];
    }
    cin >> m;
    for (ll i=0;i<m;i++){
        cin >> bx[i] >> by[i];
        v.emplace_back(bx[i],0,i);
    }
    for (ll i=0;i<n;i++){
        pair<ll,ll> p1={ax[i],ay[i]}, p2={ax[(i+1)%n],ay[(i+1)%n]};
        if (p1>p2) swap(p1,p2);
        auto [x1,y1]=p1;
        auto [x2,y2]=p2;
        l[i]=line(x1,x2,y1,y2);
        if (x1 == x2) continue;
        v.emplace_back(x1,-1,i);
        v.emplace_back(x2, 1,i);
    }
    sort(v.begin(),v.end());
    bool ok=1;
    for (auto [np,ns,i]:v){
        if (ns ==  1) s.erase(i);
        if (ns == -1) s.emplace(i);
        if (ns ==  0){
            int c1=0,c2=0,c3=0;
            for (auto j:s) {
                c1+=l[j].tud_up(bx[i],by[i]);
                c2+=l[j].tud_down(bx[i],by[i]);
                c3+= (bx[i]==l[j].x1) || (bx[i]==l[j].x2);
            }
            // cout << " => " << i << ' ' << c1 << ' ' << c2 << '\n';
            if (!c1 || !c2 || (c3==2 && s.size()==2)){
                cout << "NO";
                exit(0);
            }
        }
    }
    cout << "YES";
    return 0;
}