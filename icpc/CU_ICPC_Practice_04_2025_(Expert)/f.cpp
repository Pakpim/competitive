#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using db=double;
const int N=5005;
vector <pair<ll,ll>> v,v2;

struct line{
    db m,c,l,r,val;
    line(): m(0), c(0),l(0),r(0),val(0){}
    line(ll x1,ll y1,ll x2,ll y2):l(min(x1,x2)), r(max(x1,x2)){
        m=db(y2-y1)/db(x2-x1);
        c=db(y1)-m*db(x1);
        val=db(r-l)*db(y1+y2)*0.5;
    }
    db f(db x){
        return m*x+c;
    }
};


int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    db k,ans=0;
    cin >> n >> k;
    for (int i=0;i<n;i++){
        int x,a,b;
        cin >> x >> a >> b;
        v.emplace_back(x,b-a);
    }
    sort(v.begin(),v.end());
    for (auto [x,y]:v){
        if (y<0) continue;
        while (v2.size()>1){
            auto [x1,y1]=v2[v2.size()-1];
            auto [x2,y2]=v2[v2.size()-2];
            if (line(x,y,x2,y2).f(x1)<y1) break;
            ans-=line(x1,y1,x2,y2).val;
            v2.pop_back();
        }
        if (!v2.empty()) {
            auto [x1,y1]=v2[v2.size()-1];
            ans+=line(x,y,x1,y1).val;
        }
        v2.emplace_back(x,y);
    }
    for (auto [x,y]:v){
        if (y>=0) break;
        if ()
    }
    for (int i=v.size()-1;i>=0;i--){
        auto [x,y]=v[i];
        if (y>=0) break;
    }
    cout << ans/100.0*db(k);
}