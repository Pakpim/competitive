#include <bits/stdc++.h>
using namespace std;

const int N=1000005;
int ar[N];
multiset<int> l,r;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,w,m;
    cin >> n >> w;
    for (int i=0;i<n;i++) cin >> ar[i];
    m=ar[0];
    for (int i=1;i<=w;i++){
        if (ar[i]<m) l.emplace(ar[i]);
        else r.emplace(ar[i]);
        if (l.size()>r.size()+1){
            auto it=l.end();
            it--;
            int nv=*it;
            l.erase(it);
            r.emplace(m);
            m=nv;
        }
        else if (r.size()>l.size()+1){
            auto it=r.begin();
            int nv=*it;
            r.erase(it);
            l.emplace(m);
            m=nv;
        }
    }
    cout << m << ' ';
    for (int i=w+1;i<n;i++){
        r.emplace(m);
        if (ar[i-w-1]<*r.begin()){
            auto it =l.find(ar[i-w-1]);
            l.erase(it);
        }
        else{
            auto it =r.find(ar[i-w-1]);
            r.erase(it);
        }
        if (l.size()>r.size()+1){
            auto it=l.end();
            it--;
            int nv=*it;
            l.erase(it);
            r.emplace(nv);
        }
        else if (r.size()>l.size()+1){
            auto it=r.begin();
            int nv=*it;
            r.erase(it);
            l.emplace(nv);
        }
        if (ar[i]<*r.begin()) {
            l.emplace(ar[i]);
            auto it=l.end();
            it--;
            m=*it;
            l.erase(it);
        }
        else {
            r.emplace(ar[i]);
            auto it=r.begin();
            m=*it;
            r.erase(it);
        }
        cout << m << ' ';
    }
}