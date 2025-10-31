#include <bits/stdc++.h>
using namespace std;

const int N=200005;
int n,q,a[N],bk[N],fw[N];
vector<int> del[N],v[N];

void up (int p){
    while (p<=n){
        fw[p]--;
        p+=p&-p;
    }
    return;
}

int qu (int p){
    int re=0;
    while (p){
        re+=fw[p];
        p-=p&-p;
    }
    return re;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++){
        if (a[i]<=n) del[a[i]].emplace_back(i);
        fw[i]=i&-i;
    }
    int x=n;
    for (int i=1;i<=n;i++){
        for (auto e:del[i-1]) up(e);
        for (int j=1;j<=x;j++){
            int tmp=n+1,l=bk[j]+1,r=n,mid;
            while (l<=r){
                mid=(l+r)/2;
                int nv=qu(mid)-qu(bk[j]);
                if (nv>=j){
                    tmp=min(tmp,mid);
                    r=mid-1;
                }
                else l=mid+1;
            }
            bk[j]=tmp;
            if (tmp<=n) v[j].emplace_back(tmp);
        }
        while (bk[x]>=n) x--;
    }
    while (q--){
        int p,lv;
        cin >> p >> lv;
        auto it=lower_bound(v[lv].begin(),v[lv].end(),p);
        if (it-v[lv].begin()+1<=a[p]) cout << "YES\n";
        else cout << "NO\n";
    }
}