#include <bits/stdc++.h>
using namespace std;

using ll=long long;
bool t=0;
int cnt;
string ans="1010000110110";

bool qu (string s){
    cnt++;
    bool re=0;
    if (!t){
        cout << "? " << s << '\n';
        cout.flush();
        cin >> re;
    }
    else{
        for (int i=0;i+s.size()-1<ans.size();i++){
            for (int j=0;j<s.size();j++){
                if (s[j]!=ans[i+j]) break;
                if (j==s.size()-1) return 1;
            }
        }
    }
    return re;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        bool l=0,r=0;
        cnt=0;
        string s="";
        cin >> n;
        // n=ans.size();
        while (s.size()<n){
            if (r){
                if (qu("0"+s)) s="0"+s;
                else s="1"+s;
            }
            else{
                if (qu(s+"0"))s+="0";
                else{
                    if (qu(s+"1"))s+="1";
                    else{
                        r=1;
                    }
                }
            }
        }
        // cout << n << ' ' << cnt << '\n';
        cout << "! " << s << '\n';
        cout.flush();
    }
}