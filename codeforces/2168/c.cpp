#include <bits/stdc++.h>
using namespace std;

using ll=long long;
mt19937 rndNum;

void rnd(){
    int t;
    cin >> t;
    cout << "second\n" << t << '\n';
    while (t--){
        int n;
        cin >> n;
        vector<int> f(25,0);
        for (int i=0;i<n;i++){
            int a;
            cin >> a;
            f[a]=1;
        }
        int r=rndNum()%21;
        f[r]^=1;
        vector<int> re;
        for (int i=1;i<=20;i++){
            if (f[i]) re.emplace_back(i);
        }
        cout << re.size() << '\n';
        for (auto e:re) cout << e << ' ';
        cout << '\n';
    }
}

void dec(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> f(25);
        for (int i=0;i<n;i++){
            int a;
            cin >> a;
            f[a]=1;
        }
        int ch=0;
        for (int i=16;i<20;i++){
            if (f[i]) ch^=1;
        }
        int cnt[5]={0,0,0,0,0};
        for (int i=1;i<16;i++){
            if (!f[i]) continue;
            for (int j=0;j<4;j++){
                if (i>>j&1) cnt[j]^=1;
            }
        }
        if (ch==f[20]){
            // cout << "?";
            int x=0;
            for (int i=0;i<4;i++){
                if (cnt[i]!=f[i+16]) x|=1<<i;
            }
            // cout << x << '\n';
            f[x]^=1;
        }
        ll re=0;
        for (ll i=1;i<16;i++){
            if (f[i]) re|=1ll<<(i-1ll);
        }
        cout << re+1 << '\n';
    }
}

void enc(){
    int t;
    cin >> t;
    while (t--){
        ll a;
        cin >> a;
        a--;
        vector<int> v;
        int cnt[5]={0,0,0,0,0};
        for (ll i=0;i<15;i++){
            if (a>>i&1ll){
                v.emplace_back(i+1);
                for (int j=0;j<4;j++){
                    if ((i+1)>>j&1) cnt[j]^=1;
                }
            }
        }
        int ch=0;
        for (int i=0;i<4;i++) 
        if (cnt[i]){
            ch^=1;
            v.emplace_back(16+i);
        }
        if (ch) v.emplace_back(20);
        cout << v.size() << '\n';
        for (auto e:v) cout << e << ' ';
        cout << '\n';
    }
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    string t;
    cin >> t;
    if (t=="first") enc();
    else if (t=="rnd") rnd();
    else dec();
}