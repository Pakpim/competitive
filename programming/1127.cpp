#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=1e7;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int val[10];
    vector<int> ans;
    deque<pair<int,int>>dq;
    for (int i=1;i<=9;i++) cin >> val[i];   
    for (int i=1;i<=9;i++){
        while (!dq.empty() && dq.back().first>=val[i]) dq.pop_back();
        dq.emplace_back(val[i],i);
    }
    for (int i=0;i<n/dq.front().first;i++){
        ans.emplace_back(dq.front().second);
    }
    n%=dq.front().first;
    int p1=0,p2=dq.size()-1;
    while (p1<ans.size() && p2>0){
        while (p2>0 && dq[p2].first-dq.front().first>n) p2--;
        ans[p1]=dq[p2].second;
        p1++;
        n-=dq[p2].first-dq.front().first;
    }
    for (auto e:ans) cout << e;
}