/*
I hate geo 🙉🙈 It's coarse and rough and irritating and it gets everywhere
*/

#include<bits/stdc++.h>
using namespace std;

using ll=long long;

const int N=1e5+5;
ll x0[N],_y0[N],x1[N],_y1[N],fw[N];

void up(int i, int v){
    while (i<N){
        fw[i]+=v;
        i+=i&-i;
    }
}

int qu(int i){
    int re=0;
    while (i){
        re+=fw[i];
        i-=i&-i;
    }
    return re;
}

signed main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<tuple<int,int,int>> event; // 0 add, 1 qu, 2 rm
    vector<ll> px, py;
    for (int i=0;i<n;i++){
        cin >> x0[i] >> _y0[i] >> x1[i] >> _y1[i];
        px.emplace_back(x0[i]);
        px.emplace_back(x1[i]);
        py.emplace_back(_y0[i]);
        py.emplace_back(_y1[i]);
        if (x0[i]==x1[i]){
            if (_y0[i]>_y1[i]) swap(_y0[i],_y1[i]);
            event.emplace_back(_y0[i],0,i);
            event.emplace_back(_y1[i],2,i);
        }
        else{
            if (x0[i]>x1[i]) swap(x0[i],x1[i]);
            event.emplace_back(_y0[i],1,i);
        }
    }
    sort(event.begin(),event.end());
    sort(px.begin(),px.end());
    sort(py.begin(),py.end());
    px.erase(unique(px.begin(),px.end()), px.end());
    py.erase(unique(py.begin(),py.end()), py.end());
    for (int i=0;i<n;i++){
        x0[i]=lower_bound(px.begin(),px.end(),x0[i])-px.begin()+2;
        x1[i]=lower_bound(px.begin(),px.end(),x1[i])-px.begin()+2;
        _y0[i]=lower_bound(py.begin(),py.end(),_y0[i])-py.begin()+2;
        _y1[i]=lower_bound(py.begin(),py.end(),_y1[i])-py.begin()+2;
    }
    ll ans=0;
    for (auto [ny,ns,ni]:event){
        if (ns==0){
            up(x0[ni],1);
        }
        if (ns==1){
            ans+=qu(x1[ni])-qu(x0[ni]-1);
        }
        if (ns==2){
            up(x0[ni],-1);
        }
        // cout << " ? " << ny << ' ' << ns << ' ' << ni << " : ";
        // for (int i=2;i<=14;i++) cout << qu(i)-qu(i-1) << ' ';
        // cout << "= " << ans << '\n';
    }
    cout << ans << '\n';
}