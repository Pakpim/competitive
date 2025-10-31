#include <bits/stdc++.h>
using namespace std;

using bs=bitset<5>;
const int N=1e6+5;
pair<int,string> dp[N];
vector<int> p;
bool f[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    for (int i=2;i<N;i++){
        if (f[i]) continue;
        p.emplace_back(i);
        for (int j=i*2;j<N;j+=i) f[j]=1;
    }
    int t=1;
    // cin >> t;
    while (t--){
        int n;
        cin >> n;
        int tmp=n,c[5]={0,0,0,0,0};
        vector<int> fc;
        while (tmp>1){
            for (auto e:p){
                while (tmp%e==0){
                    tmp/=e;
                    if (e<4) c[e]++;
                    else fc.emplace_back(e);
                }
            }
        }
        for (;c[2]>1;c[2]-=2) fc.emplace_back(4);
        if (c[2] && c[3]) fc.emplace_back(6),c[2]--,c[3]--;
        if (c[2]) fc.emplace_back(2);
        for (;c[3];c[3]--) fc.emplace_back(3);
        sort(fc.begin(),fc.end());
        for (auto e:fc){
            cout << "AC";
            for (int i=0;i<e;i++) cout << "V";
        }
        // printf("if (i==%d) cout << \"%s\" << \'\\n\'; \n",n,dp[(1<<sz)-1].second.c_str());
    }
}

/*
10
9 30 1219 50220 124609 508394 649424 882660 945595 1000000
*/