#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=3e5+5;
ll a[N];

void rec (int nl,int nr, deque<string> &re){
    string sl=to_string(nl), sr=to_string(nr);
    string tmp="["+sl+";";
    if (nl+1==nr){
        tmp+=sr+")";
        re.emplace_back(tmp);
        return;
    }
    int mid = (nl+nr)/2;
    deque<string> l,r;
    rec(nl , mid, l);
    rec(mid,nr, r);
    if (l.size()<r.size()){
        string tmp ="";
        for (auto e:l.back()) tmp+= (e=='|')? "|":" ";
        l.emplace_back(tmp);
    }
    int sz=l.back().size();
    for (int i=0;i<l.size();i++){
        while (l[i].size()<sz) l[i]+=" ";
        re.emplace_back(l[i]+" | "+r[i]);
    }
    while (tmp.size()<l.back().size()+2) tmp=" "+tmp; 
    tmp+=sr+")";
    re.emplace_front(tmp);
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n;
    cin >> n;
    deque<string> ans;
    rec(0,n,ans);
    for (auto e:ans) cout << e << '\n';
}