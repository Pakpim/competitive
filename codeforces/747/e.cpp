#include <bits/stdc++.h>
using namespace std;

const int N=1e6+5;
int cnt[N],par[N];
string a[N];
vector<int> v[N];
stack<pair<int,int>> st;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    s+=",";
    int p=1, state=0, nv=0;
    string ns="";
    st.emplace(0,1e9);
    for (auto e:s){
        if (e==','){
            // cout << " ? "<< state << ' ' << p << ' ' << ns << ' ' << nv << '\n';
            if (state == 0){
                a[p]=ns;
                ns="";
                state=1;
            }
            else{
                par[p]=st.top().first;
                st.top().second--;
                if (st.top().second<=0) st.pop();
                if (nv) st.emplace(p,nv);
                nv=0;
                state=0;
                p++;
            }
        }
        else{
            if (state == 0){
                ns+=e;
            }
            if (state == 1){
                nv=nv*10+e-'0';
            }
        }
    }
    int mx=0;
    for (int i=1;i<p;i++){
        cnt[i]=cnt[par[i]]+1;
        v[cnt[i]].emplace_back(i);
        mx=max(mx,cnt[i]);
        // cout << i << ' ' << a[i] << ' ' << cnt[i] << '\n';
    }
    cout << mx << '\n';
    for (int i=1;i<=mx;i++){
        for (auto e:v[i]) cout << a[e] << ' ';
        cout << '\n';
    }
}