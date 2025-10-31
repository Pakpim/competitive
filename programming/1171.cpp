#include <bits/stdc++.h>
using namespace std;

using lll=__int128_t;
using ll=long long;
const lll MX=9223372036854775807;
lll a,k;
mt19937_64 rnd;

lll to_num (vector<lll> &v){
    lll re=0,tmp=1;
    for (int i=0;i<20;i++) {
        re+=v[i]*tmp,tmp*=lll(10);
    }
    return re;
}

void print (lll val){
    if (val==0){
        cout << 0;
        return;
    }
    vector<ll> tmp={};
    while (val){
        tmp.emplace_back(val%10);
        val/=10;
    }
    reverse(tmp.begin(),tmp.end());
    for (auto e:tmp) cout << e;
}

lll solve (){
    lll sum=0,p=0,tmp=a;
    if (k==0){
        return 0;
    }
    vector<lll> v(22,0),v2,v3;
    while (tmp){
        v[p]=tmp%10;
        sum+=tmp%10;
        tmp/=10;
        p++;
    }
    p=0;
    v2=v;
    v3=v;
    lll ans;
    if (sum>k){
        lll tmp=sum;
        while (tmp!=k){
            tmp--;
            while (v2[p]==0) p++;
            v2[p]--;
        }
        ans=to_num(v2);
        p=0;
        tmp=sum-k+1;
        while (tmp>0 || v3[p]==9){
            tmp-=v3[p];
            v3[p]=0;
            p++;
        }
        v3[p]++;
        p=0;
        while (tmp<0){
            tmp++;
            while (v3[p]==9) p++;
            v3[p]++;
        }
        if (to_num(v3)-a<a-ans) ans=to_num(v3);
        // cout << " => " << to_num(v2) << ' '  << to_num(v3) << '\n';
    }
    else{
        lll tmp=sum;
        while (tmp!=k){
            tmp++;
            while (v2[p]==9) p++;
            v2[p]++;
        }
        ans=to_num(v2);
        p=0;
        tmp=k-sum+1;
        while ((tmp>0 || v3[p]==0)&& p<21){
            tmp-=9-v3[p];
            v3[p]=9;
            p++;
        }
        if (p<20){
            v3[p]--;
            p=0;
            while (tmp<0){
                tmp++;
                while (v3[p]==0) p++;
                v3[p]--;
            }
            if (a-to_num(v3)<=ans-a) ans=to_num(v3);
        }
        //  cout << " => " << to_num(v2) << ' '  << to_num(v3) << '\n';
    }
    return ans;
}

lll solve2(){
    auto sum = [](lll val){
        lll re=0;
        while (val){
            re+=val%10;
            val/=10;
        }
        return re;
    };
    for (lll i=0;a-i>=0 || a<=MX-i;i++){
        if (a-i>=0 && sum(a-i)==k) return a-i;
        if (a<=MX-i && sum(a+i)==k) return a+i;
    }
    return -1;
}

int main (){
    bool test=0;
    if (!test) ios::sync_with_stdio(0), cin.tie(0);
    int t=10000;
    if (!test) cin >> t;
    while (t--){
        ll a,k;
        a=rnd()%1000000;
        // k=rnd()%163;
        k=rnd()%70;
        if (!test) cin >> a >> k;
        ::a=a; ::k=k;
        if (test){
            cout << a << ' ' << k << '\n';
            lll a1=solve(),a2=solve2();
            cout << " = ";print(a1); cout << ' ' ; print(a2); cout << '\n';
            if (a1!=a2){
                cout << a << ' ' << k << '\n';
                print(a1); cout << ' ' ; print(a2); cout << '\n';
                break;
            }
        }
        else print(solve()), cout << '\n';
        // else cout << solve() << '\n';
    }
}

/*
3
9223372036854775807 88
9223372036854775807 90
9223372036854775807 80
9223372036854775807 88
*/