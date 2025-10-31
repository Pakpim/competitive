#include <bits/stdc++.h>
using namespace std;

const int N=1000006;
int ar[N],cnt,sum;
bool vis[N];
mt19937 rnd(time(nullptr));
bool test=0;

int qu (int l,int r){
    // cout << " => " <<  l << ' ' << r << ' ' << r-l+1 << '\n';
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
        vis[p2.second]=1;
        return p2.second;
    }
    else{
        cout << "? " << l << ' '<< r << '\n';
        cout.flush();
        int re;
        cin >> re;
        vis[re]=1;
        return re;
    }
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t,n=2;
    cin >> t;
    while (t--){
        int np=0,tmp;
        if (test){
            n=(rnd())%1000+2;
            // n++;
            // n=153667;
            sum=0;
            cnt=0;
            for (int i=1;i<=n;i++) ar[i]=i;
            shuffle(ar+1,ar+n+1,rnd);
            for (int i=2;i<=n;i++) ar[i]=i-1;
            ar[1]=n;
        }
        else cin >> n;
        for (int i=1;i<=n;i++) vis[i]=0;
        int l=1,r=n,mid;
        while (r-l>2){
            int sz=r-l+1;
            if (np<l || np>r){
                np=qu(l,r);
            }
            mid=(l+r)/2;
            if (np>mid) {
                if (sz%4 == 1) mid = l-1 + (sz-sz%4)/2;
                if (sz%4 == 2) mid = l-1 + (sz-sz%4)/2;
                if (sz%4 == 3) mid = l-1 + (sz-sz%4)/2 +2;
            }
            else{
                if (sz%4 == 1) mid = l-1 + (sz-sz%4)/2 +1;
                if (sz%4 == 2) mid = l-1 + (sz-sz%4)/2;
                if (sz%4 == 3) mid = l-1 + (sz-sz%4)/2 +1;
            }
            // cout << " = > " << l << ' ' << r << ' ' << sz << ' ' << mid << ' ' << np << '\n';
            if (np<=mid){
                tmp=qu(l,mid);
                if (tmp==np) r=mid;
                else l=mid+1;
            }
            else {
                tmp=qu(mid+1,r);
                if (tmp==np) l=mid+1;
                else r=mid;
            }
            while (vis[l] && r-l>=2) l++;
            while (vis[r] && r-l>=2) r--;
            if (l+2>=r) break;
            mid=(l+r)/2;
            if (np>=l && np<=r){
                if (np<=mid){
                    tmp=qu(l,mid);
                    if (tmp==np) r=mid;
                    else l=mid+1;
                }
                else {
                    tmp=qu(mid+1,r);
                    if (tmp==np) l=mid+1;
                    else r=mid;
                }
            }
            else{
                if (np<l){
                    tmp=qu(np,mid);
                    if (tmp==np) r=mid;
                    else l=mid+1;
                }
                else {
                    tmp=qu(mid+1,np);
                    if (tmp==np) l=mid+1;
                    else r=mid;
                }
            }
            while (vis[l] && r-l>=2) l++;
            while (vis[r] && r-l>=2) r--;
        }
        int ans=0;
        if (l+2==r){
            // mid=(l+r)/2;
            // if (np<l || np>mid) np=qu(l,mid);
            // if (np==l){
            //     tmp=qu(mid,r);
            //     if (tmp==r) ans=mid;
            //     else ans=r;
            // }
            // if (np==mid){
            //     tmp=qu(l,r);
            //     if (tmp==mid || tmp==r) ans = l;
            //     else ans = r;
            // }
            np=qu(l,r);
            mid=(l+r)/2;
             if (np==l){
                tmp=qu(l,mid);
                if (tmp==np) ans=mid;
                else ans=r;
            }
            if (np==mid){
                tmp=qu(l,np);
                if (tmp==np) ans = l;
                else ans = r;
            }
            if (np==r){
                tmp=qu(mid,r);
                if (tmp==np) ans=mid;
                else ans=l;
            }
        }
        else {
            if (np<l || np>r){
                np=qu(l,r);
            }
            if (l==np) ans=r;
            else ans=l;
        }
        if (test && (ar[ans]!=n || cnt > ceil(1.5*log2(n)) || sum > 3*n)) {
            cout << "! wrong ";
            cout << n << ' ' << ceil(1.5*log2(n))-cnt <<  ' ' << 3*n-sum << '\n';

        }
        if (!test){
            cout << "! " << ans << '\n';
            cout.flush();
        }
        // cout << ans <<' ' << cnt << ' ' << sum << '\n';
        if (cnt > ceil(1.5*log2(n)) || sum > 3*n) exit(1);
    }
}