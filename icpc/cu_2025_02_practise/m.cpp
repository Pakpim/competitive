#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=2e5+5;
int l[N],r[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n,mx=0;
        cin >> n;
        vector<tuple<int,int,int>> v;
        vector<int> p1,p2;
        for (int i=0;i<n;i++) {
            cin >> l[i] >> r[i];
            p1.emplace_back(l[i]);
            p1.emplace_back(r[i]);
            v.emplace_back(l[i],0,i);
            v.emplace_back(r[i],1,i);
        }
        sort(v.begin(),v.end());
        sort(p1.begin(),p1.end());
        for (auto e:p1) if (p2.empty() || e>p2.back()) p2.emplace_back(e);
        auto idx = [&p2](int np){
            int re = 1+lower_bound(p2.begin(),p2.end(),np)-p2.begin();
            return re;
        };
        vector<int> fw(p2.size()+5,0);
        int cnt=0;
        auto qu = [&fw, &cnt](int np){
            int re=cnt;
            for (int i=np;i;i-=i&-i) re-=fw[i];
            return re;
        };
        auto up = [&fw, &cnt](int np){
            cnt++;
            for (int i=np;i<fw.size();i+=i&-i) fw[i]++;
        };
        for (auto [np,ns,ni]:v){
            if (ns) mx=max(mx,qu(idx(l[ni])-1));
            else up(idx(r[ni]));
        }
        cout << n-mx << '\n';
    }
}