#include <bits/stdc++.h>
using namespace std;

const int N=300005;
set<pair<int,int>> s;
int ar[N];
map<int,int> id;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i=0;i<n;i++){
        int x;
        cin >> x;
        id[x]=i;
    }
    while (m--){
        int x;
        cin >> x;
        if (x==1){
            int a,b;
            cin >> a >> b;
            if (id.find(a)==id.end()) continue;
            auto it = s.find(make_pair(ar[id[a]],a));
            if (it!=s.end()) s.erase(it);
            ar[id[a]]+=b;
            s.emplace(ar[id[a]],a);
        }
        else{
            int k;
            cin >> k;
            auto it = s.lower_bound(make_pair(k,0));
            if (it==s.begin()) cout << "NONE\n";
            else cout << prev(it)->second << '\n';
        }
    }
}