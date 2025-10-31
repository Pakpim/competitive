#include <bits/stdc++.h>
using namespace std;

const int N=1000006;
int ar[N],cnt,sum;
mt19937 rnd(time(nullptr));
bool test=1;

int qu (int l,int r){
    if (test){
        pair<int,int> p1={0,0},p2={0,0};
        for (int i=l;i<=r;i++){
            if (p2.first<ar[i]){
                p2={ar[i],i};
            }
            if (p2>p1) swap(p1,p2);
        }
        sum+=r-l+1;
        cnt++;
        return p2.second;
    }
    else{
        cout << "? " << l << ' '<< r << '\n';
        cout.flush();
        int re;
        cin >> re;
        return re;
    }
}

pair<int,int> cal (int l,int r){
    int fx=0,sx=0,mid=(l+r)/2,tmp;
    if (l+2==r){
        sx=qu(l,r);
        mid=(l+r)/2;
            if (sx==l){
            tmp=qu(l,mid);
            if (tmp==sx) fx=mid;
            else fx=r;
        }
        if (sx==mid){
            tmp=qu(l,sx);
            if (tmp==sx) fx = l;
            else fx = r;
        }
        if (sx==r){
            tmp=qu(mid,r);
            if (tmp==sx) fx=mid;
            else fx=l;
        }
        return {fx,sx};
    }
    if (l+1==r){
        sx=qu(l,r);
        if (l==sx) fx=r;
        else fx=l;
        return {fx,sx};
    }
    auto [fxl,sxl]=cal(l,mid);
    auto [fxr,sxr]=cal(mid+1,r);
    tmp=qu(l,r);
    cout << " => " << l << ' ' << r << '\n';
    if (tmp==fxl) return {fxr,fxl};
    if (tmp==sxl) return {fxl,sxl};
    if (tmp==fxr) return {fxl,fxr};
    if (tmp==sxr) return {fxr,sxr};
    return {0,0};
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n,np=0,tmp,ans=0;
        if (test){
            n=(rnd())%10;
            sum=0;
            cnt=0;
            for (int i=1;i<=n;i++) ar[i]=i;
            shuffle(ar+1,ar+n+1,rnd);
        }
        else cin >> n;
        ans=cal(1,n).first;
        if (test && (ar[ans]!=n || cnt > ceil(1.5*log2(n)) || sum > 3*n)) {
            cout << "! wrong ";
            cout << ceil(1.5*log2(n))-cnt <<  ' ' << 3*n-sum << '\n';

        }
        if (!test){
            cout << "! " << ans << '\n';
            cout.flush();
        }
        if (cnt > ceil(1.5*log2(n)) || sum > 3*n) exit(1);
    }
}