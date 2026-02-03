#include <bits/stdc++.h>
using namespace std;

const int N=24*60*60 + 5;
int n, nn, ans=-1, idx[6]={0,1,3,4,6,7}, val[6]={60*60*10, 60*60, 60*10, 60, 10, 1}, vmx[6]={2,9,5,9,5,9}, a[N], b[N], c[N];
string ns, s[N];

bool ch (string tg, int nv){
    for (int i=0;i<6;nv%=val[i], i++){
        if (tg[idx[i]]=='X') continue;
        if (tg[idx[i]]-'0'!=nv/val[i]) return 0;
    }
    return 1;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> ns;
    for (int i=0;i<6;i++) nn+=(ns[idx[i]]-'0')*val[i];
    for (int i=1;i<=n;i++) cin >> s[i];
    for (int i=1;i<=n;i++) a[i]=b[i]=c[i]=-1;
    for (int i=0, p=1;i<24*60*60 && p<=n;i++){
        if (ch(s[p], i)) a[p++]=i;
    }
    for (int i=24*60*60-1, p=n;i>=0 && p>0;i--){
        if (ch(s[p], i)) b[p--]=i;
    }
    for (int i=nn-1, p=n;i>=0 && p>0;i--){
        if (ch(s[p], i)) c[p--]=i;
    }
    a[0]=-1;
    for (int i=1;i<=n;i++){
        if (a[i-1]>=nn || b[i]<nn) continue;
        ans=max(ans, b[i]-nn);
    }
    // for (int i=1;i<=n;i++) cout << s[i] << " = " << a[i]/3600 << ':' << a[i]%3600/60 << ':' << a[i]%60 << '\n';
    // for (int i=1;i<=n;i++) cout << s[i] << " = " << b[i]/3600 << ':' << b[i]%3600/60 << ':' << b[i]%60 << '\n';
    // for (int i=1;i<=n;i++) cout << s[i] << " = " << c[i]/3600 << ':' << c[i]%3600/60 << ':' << c[i]%60 << '\n';
    if (c[1]!=-1) ans=max(ans, 24*60*60-(nn-c[1]));
    cout << ans;
}