#include <bits/stdc++.h>
using namespace std;

using ti=tuple<int,int,int>;
const int N=500005;
bool f[1005],ok[N];
int cnt[N];
vector<int> p;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int a,b,c,d;
    ti mx={0,0,0};
    cin >> a >> b >> c >> d;
    for (int i=2;i<=1000;i++){
        if (f[i]) continue;
        p.emplace_back(i);
        for (int j=i;j<=1000;j+=i) f[j]=1;
    }
    ok[1]=1;
    for (int i=2;i<N;i++){
        int bf=i;
        for (auto np:p){
            if (i%np==0){
                bf/=np;
                break;
            }
        }
        if (bf==i) bf=1;
        if (!ok[bf]) continue;
        if ((b/i)*i<a || (d/i)*i<c) continue;
        ok[i]=1;
        cnt[i]=cnt[bf]+1;
        ti nt={cnt[i],(b/i)*i+(d/i)*i,(b/i)*i};
        mx=max(mx,nt);
    }
    auto [mxp,mxs,mxx]=mx;
    cout << mxx << ' ' << mxs-mxx;
}