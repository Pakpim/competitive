// #include "bits/stdc++.h"
#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        string s;
        cin >> n >> s;
        if (n&1){
            cout << "-1\n";
            continue;
        }
        int cnt=0,l=0,r=n;
        vector <int> v;
        deque<int> dq;
        for (int i=0;i<n;i++) dq.push_back(s[i]-'0');
        while (!dq.empty() && cnt<300){
            cnt++;
            if (dq.front()!=dq.back()){
                l++;
                r--;
                dq.pop_front();
                dq.pop_back();
                continue;
            }
            if (dq.front()==0){
                v.push_back(r);
                l++;
                r++;
                dq.pop_front();
                dq.push_back(0);
            }
            else if (dq.back()==1){
                v.push_back(l);
                l++;
                r++;
                dq.pop_back();
                dq.push_front(1);
            }
        }
        if (!dq.empty())cout << "-1\n";
        else{
            cout << v.size() << '\n';
            for (int i=0;i<v.size();i++) cout << v[i] << ' ';
            cout << '\n';
        }
    }
}