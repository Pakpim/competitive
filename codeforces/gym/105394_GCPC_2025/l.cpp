#include <bits/stdc++.h>
using namespace std;

using ll=long long;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll k,cnt=0,mn=1e18;
        cin >> k;
        vector<ll> v(7,0);
        //  A, B, C, AB, BC, AC, ABC.
        for (auto &e:v) {
            cin >> e;
        }
        for (int i=0;i<3;i++){
            cnt+=v[i]/k;
            v[i]%=k;
        }
        for (int i=3;i<6;i++){ // ab = i
            for (int j=0;j<2;j++){
                int a = (i+j)%3, b = (i+(j^1))%3, c = (i+2)%3;
                int bc = 3+(i+j+1)%3, ac = 3+(i+(j^1)+1)%3;
                ll nc=0,sum=0,tmp,tmp2;
                vector<ll> nv=v;
                nv[a]+=nv[i];
                nv[i]=0;
                nc+=nv[a]/k;
                nv[a]%=k;
                if (nv[a]){ // a
                    tmp=min(k-nv[a],nv[i]);
                    tmp2=min(k-nv[a]-tmp,nv[ac]);
                    sum+=k-nv[a]-tmp-tmp2;
                    nc++;
                    nv[ac]-=tmp2;
                    nv[a]=0;
                }
                nv[c]+=nv[ac];
                nv[ac]=0;
                nc+=nv[c]/k;
                nv[c]%=k;
                if (nv[c]){ 
                    tmp = min(k-nv[c],nv[bc]);
                    sum+=k-nv[c]-tmp;
                    nc++;
                    nv[c]=0;
                    nv[bc]-=tmp;
                }
                nv[b]+=nv[bc];
                nv[bc]=0;
                nc+=nv[b]/k;
                nv[b]%=k;
                if (nv[b]){
                    sum+=k-nv[b];
                    nc++;
                    nv[b]=0;
                }
                nv[6]-=min(nv[6],sum);
                nc+=nv[6]/k + bool(nv[6]%k);
                mn=min(mn,nc);
                // cout << " ? " << a << ' ' << b << ' ' << c << ' ' << i << ' ' << bc << ' ' << ac << " = " << nc << '\n';
            }
        }
        cout << cnt+mn << '\n';
    }
}