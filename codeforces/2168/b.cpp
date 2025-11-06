#include <bits/stdc++.h>
using namespace std;

using ll=long long;
mt19937 rndNum;

int ask (int l,int r){
    int re;
    cout << "? " << l << ' ' << r << '\n';
    cout.flush();
    cin >> re;
    assert(re!=-1);
    return re;
}

void answer (int p){
    cout << "! " << p << '\n';
    cout.flush();
}

void dec(){
    int t;
    cin >> t;
    while (t--){
        int n,x;
        cin >> n >> x;
        int l, r, mid, ans;
        if (x){
            l=2, r=n, mid,ans=n+1;
            while (l<=r){
                mid=(l+r)/2;
                int nv=ask(1,mid);
                if (nv<n-1){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                    ans=min(ans,mid);
                }
            }
        }
        else{
            l=1, r=n-1, ans=0;
            while (l<=r){
                mid=(l+r)/2;
                int nv=ask(mid,n);
                if (nv<n-1){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                    ans=max(ans,mid);
                }
            }
        }
        answer(ans);
    }
}

void enc(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        bool f1=0,f2=0;
        for (int i=1;i<=n;i++){
            int a;
            cin >> a;
            if (f1) continue;
            if (a==1){
                f1=1;
                f2=1;
            }
            if (a==n){
                f1=1;
            }
        }
        cout << f2 << '\n';
    }
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    string t;
    cin >> t;
    if (t=="first") enc();
    else dec();
}