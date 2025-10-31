#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=32768;
vector<ll> g[N+1];
bool f[N+1];
ll x,np=1,bp=0,sum=0,vc=0,ec=0;

ll ch (){
    ll re=0;
    stack<int> s;
    s.emplace(1);
    while (!s.empty()){
        auto nn=s.top();
        s.pop();
        f[nn]=1;
        // cout << " => " << nn << ' ' << g[nn].size() << '\n';
        for (auto e:g[nn]){
            re++;
            if (!f[e]) s.emplace(e);
        }
    }
    return re;
}

void add (ll n,ll st){
    for (int i=st;i<st+n;i++){
        if (i==st+1) continue;
        g[st+1].emplace_back(i);
        g[i].emplace_back(st+1);
        if (i!=st && i!=st+n-1){
            g[i].emplace_back(i+1);
            g[i+1].emplace_back(i);
        }
    }
    g[st].emplace_back(st+2);
    g[st+2].emplace_back(st);
    g[st].emplace_back(st+n-1);
    g[st+n-1].emplace_back(st);
    sum+=n*n+n+1;
    ec+=(n-1)*2;
    vc+=n;
    np+=n;
    bp=st;
}

void add11 (ll st){
    g[st].emplace_back(st+1);
    g[st+1].emplace_back(st);
    g[st].emplace_back(st+3);
    g[st+3].emplace_back(st);
    g[st+1].emplace_back(st+3);
    g[st+3].emplace_back(st+1);
    g[st+1].emplace_back(st+2);
    g[st+2].emplace_back(st+1);
    bp=st;
    np=st+4;
    sum+=11;
    ec+=4;
    vc+=4;
}

ll cal (ll n){
    return n*n+n+1;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> x;
    for (ll i=31623;i>3;i--){
        ll nv=cal(i);
        if (bp){
            nv+=2;
        }
        if (x>=nv && (((x-nv)&1 && x-nv>=13) || !((x-nv)&1))){
            if (bp){
                g[bp].emplace_back(np);
                g[np].emplace_back(bp);
                sum+=2;
                ec++;
            }
            add(i,np);
            x-=nv;
        }
    }
    if (x&1){
        if (bp){
            g[bp].emplace_back(np);
            g[np].emplace_back(bp);
            sum+=2;
            ec++;
            x-=2;
        }
        add11(np);
        x-=11;
    }
    if (x<0){
        cout << "-1 -1";
        return 0;
    }
    while (x){
        if (!bp){
            bp=1;
            np=2;
            vc++;
        }
        g[bp].emplace_back(np);
        g[np].emplace_back(bp);
        bp=np;
        np=np+1;
        sum+=2;
        ec++;
        vc++;
        x-=2;
    }
    cout << vc << ' ' << ec << '\n';
    for (int i=1;i<np;i++){
        sort(g[i].begin(),g[i].end());
        for (auto e:g[i]) if (i<e) cout << i << ' ' << e << '\n';
    }
    // cout << ch();
}