#include <bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int a[N],p[N];
map<int,set<pair<int,int>>> mp;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        mp.clear();
        for (int i=1;i<=n;i++){
            cin >> a[i];
            p[a[i]]=i;
        }
        if (n==1){
            cout << "Yes\n";
            continue;
        }
        if (!((p[1]== 1 && p[2]==n) || (p[1]==n && p[2]==1))){
            cout << "No\n";
            continue;
        }
        bool ok=1;
        mp[(2+n-1)/2-1].emplace(2,n-1);
        for (int i=3;i<=n;i++){
            auto it=mp.end();
            it--;
            auto &[k,s]=*it;
            // cout << k << " => ";
            // for (auto [l,r]:s) cout << l << ',' << r << "   ";
            // cout <<'\n';
            auto it2=s.upper_bound(make_pair(p[i],1e9));
            if (it2==s.begin()){
                ok=0;
                break;
            }
            it2--;
            auto [l,r]=*it2;
            int mn=min(r-p[i]+1,p[i]-l+1);
            if (r<p[i] || l>p[i] || mn<k){
                ok=0;
                break;
            }
            s.erase(it2);
            if (s.empty()){
                mp.erase(it);
            }
            if (p[i]-1>=l){
                // cout << "!" << (p[i]-1+l)/2 << ' ' << (l-1) << '\n';
                mp[(p[i]-1+l)/2-(l-1)].emplace(l,p[i]-1);
            }
            if (r>=p[i]+1){
                mp[(r+p[i]+1)/2-(p[i])].emplace(p[i]+1,r);
            }
            // cout << " => " << i << ' ' << p[i] << '\n';
        }
        if (ok) cout << "Yes\n";
        else cout << "No\n";
    }
}