#include <bits/stdc++.h>
using namespace std;

const int N=1e6+5,R=30;
int cnt[R];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    int n=s.size()/2;
    for (auto e:s) cnt[e-'a']++;
    vector<pair<int,int>> v;
    for (int i=0;i<26;i++) if (cnt[i]) v.emplace_back(cnt[i], i);
    sort(v.begin(),v.end());
    // for (auto [cnt,ch]:v) cout << " => " << cnt << ' ' << char(ch+'a') << '\n';
    if (s.size()==2 && v.size()==2){
        cout << "YES\n";
        cout << s;
        return 0;
    }
    if (s.size()==4 && v.size()==2 && v[0].first==2){
        cout << "YES\n";
        for (auto [cnt,ch]:v){
            for (int i=0;i<cnt;i++) cout << char(ch+'a');
        }
        return 0;
    }
    if (v.size()<2 || (v.size()==2 && v[0].first<3)){
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    if (v.size()==2){
        for (int i=0;i<min(v[1].first,n);i++) cout << char(v[1].second+'a');
        for (int i=0;i<v[0].first-1;i++) cout << char(v[0].second+'a');
        for (int i=0;i<v[1].first-(v[1].first,n);i++) cout << char(v[1].second+'a');
        cout << char(v[0].second+'a');
        return 0;
    }
    for (int i=0;i<min(n,v.back().first);i++) cout << char(v.back().second+'a');
    v.back().first-=min(n,v.back().first);
    cout << char(v[0].second+'a'); v[0].first--;  v[1].first--;
    for (auto [cnt,ch]:v){
        for (int i=0;i<cnt;i++) cout << char(ch+'a');
    }
    cout << char(v[1].second+'a');
}