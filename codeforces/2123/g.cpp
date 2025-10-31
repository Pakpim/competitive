#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int a[N];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n,m,q;
        cin >> n >> m >> q;
        for (int i=1;i<=n;i++) cin >>a[i];
        a[0]=0;
        a[n+1]=m-1;
        vector<int> div;
        map<int,int> id;
        for (int i=1;i*i<=m;i++){
            if (m%i==0){
                id[i]=div.size();
                div.emplace_back(i);
                id[m/i]=div.size();
                div.emplace_back(m/i);
            }
        }
        int sz=div.size();
        vector<int> v;
        for (int i=0;i<sz;i++){
            int cnt=0;
            for (int j=2;j<=n;j++){
                if ((a[j]%div[i])<(a[j-1]%div[i])){
                    cnt++;
                }
            }
            v.emplace_back(cnt);
        }
        while (q--){
            int o;
            cin >> o;
            if (o==1){
                int p,x;
                cin >> p >> x;
                for (int i=0;i<sz;i++){
                    int nv=div[i];
                    a[0]=0; a[n+1]=nv-1;
                    if ((a[p]%nv)<(a[p-1]%nv)) v[i]--;
                    if ((a[p+1]%nv)<(a[p]%nv)) v[i]--;
                    if ((  x %nv)<(a[p-1]%nv)) v[i]++;
                    if ((a[p+1]%nv)<(  x %nv)) v[i]++;
                }
                a[p]=x;
            }
            if (o==2){
                int k;
                cin >> k;
                k=__gcd(k,m);
                if (v[id[k]]<m/k) cout << "YES\n";
                else cout << "NO\n";
            }
        }
    }
}