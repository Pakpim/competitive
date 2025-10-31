#include <bits/stdc++.h>
using namespace std;

bool test=1;
int N;
vector<pair<int,int>> per;
mt19937 rnd(time(NULL));

bool ans (vector<int> v){
    if (test){
        for (int i=0;i<N;i++) if (v[i]!=per[i].second) return 0;
    }
    else{
        cout << "1 ";
        for (auto e:v) cout << e << ' ';
        cout << '\n';
        cout.flush();
        exit(0);
    }
    return 1;
}

int qu (vector<int> v){
    int re=0;
    if (test){
        for (int i=0;i<N;i++) re+=(v[i]==per[i].second);
    }
    else{
        cout << "0 ";
        for (auto e:v) cout << e << ' ';
        cout << '\n';
        cout.flush();
        cin >> re;
    }
    return re;
}

void solve (){
    int n;
    if (test){
        n=rnd()%1000+1;
        per.resize(n);
        for (int i=0;i<n;i++) per[i]={rnd(),i+1};
        sort(per.begin(),per.end());
    }
    else cin >> n;
    vector<pair<int,int>> p(n);
    int ar[n+5],r[n+5];
    for (int i=0;i<n;i++) p[i]={rnd(),i+1};
    sort(p.begin(),p.end());
    for (int i=0;i<n;i++) r[p[i].second]=i+1;
    vector<int> l,r;
    vector<pair<int,int>> mid;
    for (int i=1;i<=n/2;i++){
        int a=r[i*2],b=r[i*2+1];
        
    }
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}