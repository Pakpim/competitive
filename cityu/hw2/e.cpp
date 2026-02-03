#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll M=998244353;

ll bp( ll a, ll b){
    ll re=1;
    while (b){
        if (b&1) re=(re*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    return re;
}

signed main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,q;
    string s;
    // ifstream fin("in.txt");
    cin >> n >> s >> q;
    vector<ll> num, dig;
    vector<char> op;
    ll nn=0,cnt=0;
    for (auto e:s){
        if (e>='0' && e<='9'){
            nn=((nn*10)%M + (e-'0'))%M;
            cnt++;
        }
        else{
            num.emplace_back(nn);
            dig.emplace_back(cnt);
            nn=0;
            cnt=0;
            op.emplace_back(e);
        }
    }
    dig.emplace_back(cnt);
    num.emplace_back(nn);
    if (num.size()==1){
        while(q--){
            ll k,ans;
            cin >> k;
            ans=((((bp(bp(10,dig[0]),k)-1)%M) * bp(bp(10,dig[0])-1,M-2))%M * (num[0]))%M;
            // cout << " => " << bp(bp(10,dig[0]),k)-1 << ' ' << bp(10,dig[0])-1 << ' ' << num[0] << '\n';
            if (ans<0) ans+=M;
            cout << ans << '\n';
        }
        return 0;
    }
    bool f=1;
    for (auto e:op) f&=e=='*';
    if (f){
        ll a=num.front(), b=num.back(), c=1;
        for (int i=1;i<num.size()-1;i++) c=(c*num[i])%M;
        while (q--){
            ll k, ans;
            cin >> k;
            ans=(((((a*b)%M) *bp(c,k))%M) *bp((b*bp(10,dig[0]))%M +a,k-1))%M;
            if (ans<0) ans+=M;
            cout << ans << '\n';
        }
        return 0;
    }
    ll a=num.front(), b=num.back(), x=1, y=0, z=1, l=0, r=op.size()-1;
    for (;l<op.size();l++){
        if (op[l]!='*') break;
        x=(x*(num[l+1]))%M;
    }
    for (;r>=0;r--){
        if (op[r]!='*') break;
        z=(z*(num[r]))%M;
    }
    if (op[r]=='-') z*=-1;
    ll sum=num[r];
    for (ll i=r-1;i>=l;i--){
        if (op[i]=='*') sum=(sum*(num[i]))%M;
        else{
            if (op[i]=='-') sum*=-1;
            y=(y+sum)%M;
            sum=num[i];
        }
    }
    // cout << " num: ";
    // for (auto e:num) cout << e << ' ';
    // cout << '\n';
    // cout << " op: ";
    // for (auto e:op) cout << e << ' ';
    // cout << '\n';
    // cout << " ? " << a << ' ' << b << ' ' << x << ' ' << y << ' ' << z << '\n';
    while (q--){
        ll k,ans;
        cin >> k;
        ans=(((a*x)%M) + ((b*z)%M) + ((y*k)%M) + (((b*bp(10,dig[0])%M) +a)*(k-1)%M *x%M *z%M))%M;
        if (ans<0) ans+=M;
        // cout << " => " << a*x%M << ' ' << b*z%M << ' ' << y*k%M << ' ' << (b*10+a)*(k-1)%M << '\n';
        cout << ans << '\n';
    }
}

/*
3
564
10
1 2 3 4 5 6 7 8 9 10

500
61152118874923992587*52*5395298*1314+476529*623*657*5382*7437968944833+8778+556951*97+62+739382891698*6479725*44253474+45*5*6*16525+8951*871594989446133*326225395523118*5793*2486925*7673978739+8*8735642129881263+6+588633759738*371997+1*44+4+42628671+8991*3*387551453*923231736825254727*2+8*9225175*13256*44+5*859+3549*539+2165144563+9*9433299642996*45+512+3854918298*413+754863318363+6+2+99*417859+8*8613482276594598822975533799+253317684+98*89+871+83+649+6643*531783347822*1995*9145543436955*1+71582
1
8382857

3
5*6
10
1 2 3 4 5 6 7 8 9 10
*/