#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using ti=tuple<ll,int,int>;
using bt=bitset<10>;
const int N=1e5;
ll a[N];
priority_queue<ti,vector<ti>,greater<ti>> pq;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin >> n >> k;
    for (int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    int cnt=0;
    pq.emplace(0,0,0);
    while (cnt<k){
        auto [nv,ni,ns]=pq.top();
        pq.pop();
        cnt++;
        if (cnt==k){
            cout << nv;
            break;
        }
        if (ns==0) pq.emplace(nv+a[ni],ni,1);
        else if (ni+1<n) {
            pq.emplace(nv+a[ni+1]-a[ni],ni+1,1);
            pq.emplace(nv+a[ni+1],ni+1,1);
        }
    }
}

/*
7 85
67 15 4 72 8 2 3
*/
