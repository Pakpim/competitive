#include <bits/stdc++.h>
using namespace std;

const int N=1000006;
int ar[N],cnt,sum;
mt19937 rnd;

int qu (int l,int r){
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

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n,np=0,tmp;
        cin >> n;
        // n=(rnd())%100000;
        // sum=0;
        // cnt=0;
        // for (int i=1;i<=n;i++) ar[i]=i;
        // shuffle(ar+1,ar+n+1,rnd);
        int l=1,r=n,mid;
        while (r-l>2){
            if (np<l || np>r){
                cout << "? " << l << ' ' << r << '\n';
                cout.flush();
                cin >> np;
                // np=qu(l,r);
            }
            mid=(l+r)/2;
            if (np<=mid){
                cout << "? " << l << ' ' << mid << '\n';
                cout.flush();
                cin >> tmp;
                // tmp=qu(l,mid);
                if (tmp==np) r=mid;
                else l=mid+1;
            }
            else {
                cout << "? " << mid+1 << ' ' << r << '\n';
                cout.flush();
                cin >> tmp;
                // tmp=qu(mid+1,r);
                if (tmp==np) l=mid+1;
                else r=mid;
            }
            if (l+2>=r) break;
            mid=(l+r)/2;
            if (np>=l && np<=r){
                if (np<=mid){
                    cout << "? " << l << ' ' << mid << '\n';
                    cout.flush();
                    cin >> tmp;
                    // tmp=qu(l,mid);
                    if (tmp==np) r=mid;
                    else l=mid+1;
                }
                else {
                    cout << "? " << mid+1 << ' ' << r << '\n';
                    cout.flush();
                    cin >> tmp;
                    // tmp=qu(mid+1,r);
                    if (tmp==np) l=mid+1;
                    else r=mid;
                }
            }
            else{
                if (np<l){
                    cout << "? " << np << ' ' << mid << '\n';
                    cout.flush();
                    cin >> tmp;
                    // tmp=qu(np,mid);
                    if (tmp==np) r=mid;
                    else l=mid+1;
                }
                else {
                    cout << "? " << mid+1 << ' ' << np << '\n';
                    cout.flush();
                    cin >> tmp;
                    // tmp=qu(mid+1,np);
                    if (tmp==np) l=mid+1;
                    else r=mid;
                }
            }
        }
        int ans=0;
        if (l+2==r){
            np=qu(l,r);
            mid=(l+r)/2;
             if (np==l){
                cout << "? " << l << ' ' << mid << '\n';
                cout.flush();
                cin >> tmp;
                // tmp=qu(l,mid);
                if (tmp==np) ans=mid;
                else ans=r;
            }
            if (np==mid ){
                cout << "? " << l << ' ' << np << '\n';
                cout.flush();
                cin >> tmp;
                // tmp=qu(l,np);
                if (tmp==np) ans = l;
                else ans = r;
            }
            if (np==r){
                cout << "? " << mid << ' ' << r << '\n';
                cout.flush();
                cin >> tmp;
                // tmp=qu(mid,r);
                if (tmp==np) ans=mid;
                else ans=l;
            }
        }
        else {
            if (np<l || np>r){
                cout << "? " << l << ' ' << r << '\n';
                cout.flush();
                cin >> np;
                // np=qu(l,r);
            }
            if (l==np) ans=r;
            else ans=l;
        }
        cout << "! " << ans << '\n';
        cout.flush();
        // if (ar[ans]!=n || cnt >ceil(1.5*log2(n)) || sum>3*n) {
        //     cout << "! wrong ";
        //     cout << ceil(1.5*log2(n))-cnt <<  ' ' << 3*n-sum << '\n';
        // }
    }
}