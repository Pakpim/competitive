#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll N=1505;
ll qs[N];

struct node{
    node *ch[30];
    node (){
        for (int i=0;i<26;i++) ch[i]=NULL;
    }
};

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    string a,s;
    int n,k,cnt=0;
    cin >> s >> a >> k;
    n=s.size();
    node *root = new node(), *nn=new node();
    for (int i=1;i<=n;i++){
        qs[i]=qs[i-1]+(a[s[i-1]-'a'] == '1' ? 0:1);
        nn = root;
        for (int j=i;j>0;j--){
            if (qs[i]-qs[j-1]>k) break;;
            char c=s[j-1];
            if (!nn->ch[c-'a']){
                cnt++;
                nn->ch[c-'a'] = new node();
            }
            nn = nn->ch[c-'a'];
        }
    }
    cout << cnt;
}