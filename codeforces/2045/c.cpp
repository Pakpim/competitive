#include <bits/stdc++.h>
using namespace std;

const int N=30;
int pa[N],pb[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    for (int i=0;i<26;i++) pa[i]=1e9,pb[i]=1e9;
    string a,b,c;
    int ans=1e9;
    cin >> a >> b;
    for (int i=1;i<a.size();i++) pa[a[i]-'a']=min(pa[a[i]-'a'],i);
    for (int i=0;i<b.size()-1;i++) pb[b[i]-'a']=min(pb[b[i]-'a'],int(b.size())-i-1);
    for (int i=0;i<26;i++){
        if (pa[i]==1e9 || pb[i]==1e9) continue;
        if (ans>pa[i]+pb[i]+1){
            ans=min(ans,pa[i]+pb[i]+1);
            c=a.substr(0,pa[i]+1)+b.substr(b.size()-pb[i],pb[i]);
        }
    }
    if (ans==1e9){
        cout << -1;
        return 0;
    }
    cout << c;
}