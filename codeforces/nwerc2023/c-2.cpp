#include<bits/stdc++.h>

using namespace std;

using ll = long long;
const ll N=500005;
ll n,m=n,a[N],mul=1,add=0,block=1;
ll q,m2=1,sum=0,k,j2,p;
mt19937 rnd;
bool db=0;

ll invmod(ll x,ll mod){
    ll a=x,b=mod,u=1,v=0,q=0;
    while(b>0){
        q=a/b;
        a-=q*b;
        u-=q*v;
        swap(a,b);
        swap(u,v);
    }
    u%=mod;
    if(u<0)u+=mod;
    return u;
}

ll ar[N],mn[N],tmp[N];

pair<ll,ll> inv (ll a,ll b){
    if (a==0) return {0,1};
    ll r=b%a,q=b/a;
    pair<ll,ll> p = inv(r,a);
    ll x=((p.second-q*p.first)%n+n)%n,y=p.first;
    return {x,y};
}

ll getid (ll x){
    x=(x+n-add)%n;
    if(x%block!=0)return -1;
    x/=block;
    x=(x*invmod(mul/block,m))%m;
    return a[x];
};

ll ans2(ll x){
    if (x%p!=j2)  return -1;
    else {
        ll xp = (x/p);
        xp = ((( ((((xp-sum)%k)+k)%k) *inv(m2,k).first)%k)+k)%k;
        if (db) cout << " debug = " << x << ' ' << x/p << ' ' << sum << ' ' << m2 << ' ' << k << " = " << xp  << '\n';
        return ar[xp];
    }
}

int main(){
    // cin.tie(nullptr)->sync_with_stdio(false);
    // cin >> n;
    while (1){
        ll MXN=1000;
        n=MXN+(rnd()%MXN);
        for(ll i=0;i<n;i++){
            a[i]=i;
            ar[i]=i;
        }
        m=n;
        k=n;
        p=1;
        j2=0;
        auto eliminate=[&](ll x,ll g){
            vector<pair<ll,ll>> c1(n,{n,-1});
            for(ll i=0;i<n;i++){
                if(a[i%m]!=i)continue;
                ll id=(i*mul+add)%n;
                ll j=(id*x)%n;
                c1[j]=min(c1[j],{(j+n-id)%n,i});
            }
            m/=g;
            block*=g;
            vector<ll> b(m);
            for(ll i=0;i<n;i++){
                ll j=c1[i].second;
                if(j!=-1){
                    b[j%m]=j;
                }
            }
            for (int i=0;i<m;i++) a[i]=b[i];
        };
        ll cnt=1000000;
        while(cnt--){
            char op[]={'+','*','?'};
            ll x,z;
            // cin >> op >> x;
            z=(rnd())%2;
            x=((rnd())%n)+1;
            cout << op[z] << ' ' << x << '\n';
            if(op[z]=='+'){
                add=(add+x)%n;
                j2+=x;
                sum+=j2/p;
                j2%=p;
                sum%=k;
            }
            else if(op[z]=='*'){
                ll g=gcd(x,m);
                if(g!=1)eliminate(x,g);
                mul=(mul*x)%n;
                add=(add*x)%n;
                if (__gcd(x,k)!=1){
                    ll gcd=__gcd(x,k),tj;
                    for (ll i=0;i<k;i++){
                        mn[i]=1e9;
                        ll ip = ((( ((((i-sum)%k)+k)%k) *inv(m2,k).first)%k)+k)%k;
                        tmp[i]=ar[ip];
                    }
                    for (ll i=0;i<k;i++){
                        ar[i]=tmp[i];
                    }
                    for (ll i=0;i<k;i++){
                        ll ip=(i*x*p+j2*x)%n;
                        ll d=(((ip-(i*p+j2))%n)+n)%n;
                        tj=ip%(n/(k/gcd));
                        ip/=n/(k/gcd);
                        if (mn[ip]>d){
                            mn[ip]=d;
                            tmp[ip]=ar[i];
                        }
                    }
                    k/=gcd;
                    p=n/k;
                    for (ll i=0;i<k;i++) ar[i]=tmp[i];
                    m2=1;
                    sum=0;
                    j2=tj;
                }
                else{
                    j2*=x;
                    sum*=x;
                    sum+=j2/p;
                    j2%=p;
                    sum%=k;
                    // m2*=p*x;
                    m2*=x;
                    m2%=k;
                }
            }
            else if(op[z]=='?'){
                ll a1=getid(x);
                ll a2=ans2(x);
                cout << " ans " << a1 << ' ' << a2 << '\n';
                if (a1!=a2){
                    break;
                }
            }

            for (int i=1;i<=n;i++){
                if (getid(i)!=ans2(i)){
                    cnt=-5;
                }
            }
            if (cnt==-5){
                // db=1;
                for (int i=1;i<=n;i++) if (getid(i)!=ans2(i)) cout << i << " ! " << getid(i) << ' ' << ans2(i) << '\n';
                // for (int i=0;i<k;i++) cout << ar[i] << ' ';
                // cout << '\n';
                vector<bool> vis(n+5,0);
                for (int i=0;i<k;i++){
                    if (vis[ar[i]]) cout << "duplicate!\n";
                    vis[ar[i]]=1;
                }
                break;
            }
        }

    }
}