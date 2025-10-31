#include <bits/stdc++.h>
#define lc i*2+1
#define rc i*2+2
#define mid (l+r)/2
using namespace std;

const int N=1e6+5;
int a[N];
tuple<int,int,int> sg[N*4];
string s;

void build (int l=1,int r=s.size(),int i=0){
    if (l==r){
        sg[i]={a[l]==1, a[l]==-1, 0};
        // cout << " => " << l << ' ' << get<0>(sg[i]) << ' ' << get<1>(sg[i]) << ' ' << get<2>(sg[i]) << '\n';
        return;
    }
    build(l,mid,lc);
    build(mid+1,r,rc);
    auto [op1,cl1,cnt1] = sg[lc];
    auto [op2,cl2,cnt2] = sg[rc];
    int nv = min(op1,cl2);
    sg[i]={op2 + (op1-nv), cl1 + (cl2-nv) , cnt1 + cnt2 + nv*2};
}

tuple<int,int,int> qu(int tl,int tr,int l=1,int r=s.size(),int i=0){
    if (tl>r || tr<l) return {0,0,0};
    if (tl<=l && tr>=r) return sg[i];
    auto [op1,cl1,cnt1] = qu(tl,tr,l,mid,lc);
    auto [op2,cl2,cnt2] = qu(tl,tr,mid+1,r,rc);
    int nv = min(op1,cl2);
    return {op2 + (op1-nv), cl1 + (cl2-nv) , cnt1 + cnt2 + nv*2};
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> s;
    for (int i=1;i<=s.size();i++){
        a[i] = s[i-1]=='(' ? 1:-1;
    }
    build();
    int q;
    cin >> q;
    while (q--){
        int l,r;
        cin >> l >> r;
        cout << get<2>(qu(l,r)) << '\n';
    }
}