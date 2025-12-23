#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=1e5+5;
bool f[N];
vector<int> p;

map<int,int> pf(int n){
    map<int,int> re;
    // return re;
    for (auto e:p){
        int cnt=0;
        while (n%e==0){
            cnt++;
            n/=e;
        }
        if (cnt) re.emplace(e,cnt);
    }
    if (n>1) re.emplace(n,1);
    return re;
}

void solve(){
    int a,b,c,n;
    cin >> a >> b >> c >> n;
    map<int,int> fa=pf(a), fb=pf(b), fc=pf(c), fn=pf(n);
    int x=1,y=1,z=1;
    while (!fn.empty()){
        auto [np,cnt]=*fn.begin();
        if (fa[np]>0){
            fn[np]--;
            if (fn[np]<=0) fn.erase(np);
            fa[np]--;
            if (fa[np]<=0) fa.erase(np);
            x*=np;
            continue;
        }
        if (fb[np]>0){
            fn[np]--;
            if (fn[np]<=0) fn.erase(np);
            fb[np]--;
            if (fb[np]<=0) fb.erase(np);
            y*=np;
            continue;
        }
        if (fc[np]>0){
            fn[np]--;
            if (fn[np]<=0) fn.erase(np);
            fc[np]--;
            if (fc[np]<=0) fc.erase(np);
            z*=np;
            continue;
        }
        cout << "-1\n";
        return;
    }
    // cout << x << ' ' << y << ' ' << z << '\n';
    assert(x*y*z==n);
    assert(a%x==0);
    assert(b%y==0);
    assert(c%z==0);
    cout << x-1 << ' ' << y-1 << ' ' << z-1 << '\n';
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    for (int i=2;i<N;i++){
        if (f[i]) continue;
        p.emplace_back(i);
        for (int j=i*2;j<N;j+=i) f[j]=1;
    }
    int t=1;
    // cin >> t;
    while (t--){
        solve();
    }
}