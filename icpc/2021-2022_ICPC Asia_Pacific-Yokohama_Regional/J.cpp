#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;

int n;
int x[N],y[N];
vector<int> xs,ys;
int ox[N],oy[N];
bool bad[N],good[N];
int lx[N],ly[N];
vector<int> qr[N],upd[N];
long long ans=0;

struct Fenwick{
    int t[N];
    void update(int i,int v){
        for(;i<N;i+=i&-i)t[i]+=v;
    }
    int query(int i){
        int res=0;
        for(;i>0;i-=i&-i)res+=t[i];
        return res;
    }
}f;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x[i] >> y[i];
        xs.emplace_back(x[i]);
        ys.emplace_back(y[i]);
    }
    sort(xs.begin(),xs.end());
    sort(ys.begin(),ys.end());
    for(int i=0;i<n;i++){
        x[i]=lower_bound(xs.begin(),xs.end(),x[i])-xs.begin()+1;
        y[i]=lower_bound(ys.begin(),ys.end(),y[i])-ys.begin()+1;
        ox[x[i]]=i;
        oy[y[i]]=i;
    }
    {
        int mx=0,mn=n+1;
        for(int _i=n;_i>=1;_i--){
            int i=ox[_i];
            mx=max(mx,y[i]);
            mn=min(mn,y[i]);
            if(mx>y[i]){
                bad[i]=true;
            }else{
                ly[i]=mn;
            }
        }
    }
    {
        int mx=0,mn=n+1;
        for(int _i=n;_i>=1;_i--){
            int i=oy[_i];
            mx=max(mx,x[i]);
            mn=min(mn,x[i]);
            if(mx>x[i]){
                bad[i]=true;
            }else{
                lx[i]=mn;
            }
        }
    }
    {
        int mn=n+1;
        for(int _i=1;_i<=n;_i++){
            int i=ox[_i];
            mn=min(mn,y[i]);
            if(mn==y[i]){
                good[i]=true;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(!bad[i]){
            qr[lx[i]].emplace_back(ly[i]);
        }
    }
    for(int i=0;i<n;i++){
        if(good[i]){
            upd[x[i]].emplace_back(y[i]);
        }
    }
    for(int p=1;p<=n;p++){
        for(auto i:upd[p]){
            f.update(i,+1);
        }
        for(auto i:qr[p]){
            ans+=f.query(i);
        }
    }
    cout << ans;
}