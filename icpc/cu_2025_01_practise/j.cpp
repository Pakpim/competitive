#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = double;
const ll N=1e5+5;
ll a[N],b[N],ans[N],n,d,x;
bool f[N];

//x is 64-bit variable;
ll getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}
void initAB() {
    int i;
    for(i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}

void cal(int l,int r){
    // cout << " ? " << l << ' ' << r << '\n';
    deque<int> dq;
    for (int i=0;i+l<n;i++){
        while(!dq.empty() && dq.front()+r-l<i){
            dq.pop_front();
        }
        while(!dq.empty() && a[dq.back()]<a[i]){
            dq.pop_back();
        }
        dq.emplace_back(i);
        // for (auto e:dq) cout << e << ' ';
        // cout << '\n';
        ans[i+l]=max(ans[i+l],a[dq.front()]);
    }
    // cout << '\n';
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> d >> x;
    initAB();
    int l=n;
    b[n]=0;
    if (d<300){
        for (int i=0;i<=n;i++){
            if (b[i]){
                l=min(l,i);
            }
            else if (l!=n) {
                cal(l,i-1);
                l=n;
            }
        }
    }
    else{
        vector<pair<ll,int>> v;
        vector<int> pb;
        for (int i=0;i<n;i++) v.emplace_back(-a[i],i);
        for (int i=0;i<n;i++) if (b[i]) pb.emplace_back(i);
        sort(v.begin(),v.end());
        for (int i=0;i<min(300ll,n);i++){
            auto [na,ni]=v[i];
            na=-na;
            for (auto e:pb){
                if (ni+e>=n) break;
                ans[ni+e]=max(ans[ni+e],na);
            }
        }
        for (int i=0;i<n;i++){
            if (!ans[i]){
                for (auto e:pb){
                    if (e>i) break;
                    ans[i]=max(ans[i],a[i-e]);
                }
            }
        }
    }
    for (int i=0;i<n;i++) cout << ans[i] << '\n';
    // int r=500,n=1e5;
    // double p=1.0;
    // for (int i=0;i<r;i++){
    //     p*=db(n-3*i)/db(n);
    // }
    // cout << p;
}