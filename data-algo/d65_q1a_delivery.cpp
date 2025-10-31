#include <bits/stdc++.h>
using namespace std;

const int N=100005;
queue<int> q[5];
int p[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,sum=0;
    cin >> n >> m;
    vector <int> p(m),v;
    for (auto &e:p) cin >> e;
    while (n--){
        int x,y,z;
        cin >> x;
        if (x==1){
            cin >> y >> z;
            q[y].emplace(z);
        }
        else{
            if (q[1].empty() || (!q[2].empty() && q[2].front()<q[1].front())){
                sum+=q[2].front();
                q[2].pop();
            }
            else{
                sum+=q[1].front();
                q[1].pop();
            }
            v.emplace_back(sum);
        }
    }
    for (auto e:p){
        auto it=lower_bound(v.begin(),v.end(),e);
        if (it==v.end()) cout << "-1 ";
        else cout << it-v.begin()+1 << ' ';
    }
}