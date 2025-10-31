#include <bits/stdc++.h>
using namespace std;

using ll=long long;
ll n,mx,cnt[200005],sum;
string a,b;

struct node{
    ll l=0,r=0,v=0;
    node *par=NULL, *suf=NULL, *ch[30];
    node():l(0),r(n),v(0),par(NULL),suf(NULL){
        for (ll i=0;i<=26;i++) ch[i]=NULL;
    }
    node(ll l,ll r,ll v):l(l),r(r),v(v),par(NULL),suf(NULL){
        for (ll i=0;i<=26;i++) ch[i]=NULL;
    }
};

vector<string> stk;
int len=0;

void debug(node *nn,int nd=0){
    string ns="";
    for (ll i=nn->l;i<=nn->r && i>=0;i++) ns+=a[i];
    stk.emplace_back(ns);
    len+=ns.size();
    if (nn->r == n){
        cout << " => " << nn->l << ' ' << nn->r << " = " << len;
        cout << "\t,suffix = ";
        for (auto e:stk) cout << e;
        cout << "\t,occ = " << nn->v << '\n';
    }
    // for (int i=0;i<nd;i++) cout << "  ";
    for (ll i=0;i<=26;i++){
        if (nn->ch[i]){
            // for (int i=0;i<nd;i++) cout << "  ";
            // cout << char(i+'a') << ":";
            debug(nn->ch[i],nd+1);
        }
    }
    // cout << "\n";
    len-=ns.size();
    stk.pop_back();
}

void dfs (node *nn,ll nd){
    for (ll i=0;i<=26;i++){
        if (nn->ch[i]){
            // assert(nn->ch[i]->par == nn);
            dfs(nn->ch[i],nd + nn->ch[i]->r - nn->ch[i]->l +1);
            nn->v+=nn->ch[i]->v;
        }
    }
    if (nn->r == n) cnt[nd]++;
    if (nn->r == n && b[n-nd+1]!='1') {
        nn->v++;
        nd--;
        sum++;
    }
    mx=max(mx,nn->v*nd);
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    // cin >> n >> a >> b;
    cin >> a;
    n=a.size();
    b="";
    for (int i=0;i<n;i++) b+='0';
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    a+=char('z'+1);
    b+='1';
    node *root = new node(), *nn = root;
    root->l=root->r=-1;
    ll np=0;
    for (ll i=0;i<=n;i++){
        node *tmp=NULL, *suf=NULL;
        cout << '\n' << i << ' ' << a[i] << " ? " << nn->l << ' ' << nn->r << ' ' << np << '\n';
        while (1){
            cout << " -> " << nn->l << ' ' << nn->r << ' ' << np << '\n';
            // assert(nn->l+np<=nn->r);
            if ((nn->l+np==nn->r && !nn->ch[a[i]-'a']) || (nn->l+np<nn->r && a[nn->l+np+1]!=a[i])){
                // cout << "a\n";
                if (nn->l+np<nn->r){
                    node *nw = new node(nn->l,nn->l+np,0);
                    nw->par = nn->par;
                    // cout << " ?? " << nw->par->l << ' ' << nw->par->r << '\n';
                    nw->par->ch[a[nw->l]-'a'] = nw;
                    nn->l = nn->l+np+1;
                    nn->par = nw;
                    nw->ch[a[nn->l]-'a'] = nn;
                    nw->ch[a[i]-'a'] = new node(i,n,0);
                    nw->ch[a[i]-'a']->par = nw;
                    if (tmp) {
                        tmp->suf = nw;
                        cout << "suffix link " << tmp->l << ' ' << tmp->r << " -> " << tmp->suf->l << ' ' << tmp->suf->r << '\n';
                    }
                    ll sp=0;
                    if (nw->par == root){
                        suf = nw->par;
                        sp = suf->r - suf->l;
                        for (ll j=nw->l+1;j<=nw->r;){
                            ll sz = suf->ch[a[j]-'a']->r - suf->ch[a[j]-'a']->l +1;
                            if (sz+j-1<nw->r){
                                sp=sz-1;
                                suf = suf->ch[a[j]-'a'];
                                j+=sz;
                            }
                            else{
                                sp=nw->r-j;
                                suf = suf->ch[a[j]-'a'];
                                break;
                            }
                        }
                    }
                    else{
                        suf = nw->par->suf;
                        sp = suf->r - suf->l;
                        for (ll j=nw->l;j<=nw->r;){
                            assert(a[j]>= 'a' && a[j]<='z'+1);
                            // assert(suf->ch[a[j]-'a']);
                            ll sz = suf->ch[a[j]-'a']->r - suf->ch[a[j]-'a']->l +1;
                            // cout << " !! " << nw->l << ' ' << nw->r << ' ' << j << ' ' << sz << ' ' << suf->l << ' ' << suf->r << '\n';
                            // assert(suf->ch[a[j]-'a']);
                            // assert(nw);
                            if (sz+j-1<nw->r){
                                // assert(suf->ch[a[j]-'a']);
                                // assert(a[suf->ch[a[j]-'a']->l] == a[j]);
                                suf = suf->ch[a[j]-'a'];
                                sp=sz-1;
                                j+=sz;
                                // assert(suf->l+sp<=suf->r);
                                }
                                else{
                                    sp=nw->r-j;
                                    // assert(suf->ch[a[j]-'a']);
                                    // assert(a[suf->ch[a[j]-'a']->l] == a[j]);
                                    suf = suf->ch[a[j]-'a'];
                                    // assert(suf->l+sp<=suf->r);
                                    break;
                                }
                            }
                        }
                        tmp = nw;
                        nn = suf;
                        np = sp;
                    }
                    else{
                        if (tmp){
                            tmp->suf = nn;
                            // assert(nn);
                            // assert(tmp->suf);
                            cout << "suffix link " << tmp->l << ' ' << tmp->r << " -> " << tmp->suf->l << ' ' << tmp->suf->r << '\n';
                        }
                        tmp=NULL;
                        nn->ch[a[i]-'a'] = new node(i,n,0);
                        nn->ch[a[i]-'a']->par = nn;
                        if (nn!=root) {
                            nn = nn->suf;
                            np=0;
                        }
                        else break;
                    }
                }
                else{
                    // cout << "b\n";
                    if (tmp){
                        tmp->suf = nn;
                        cout << "suffix link " << tmp->l << ' ' << tmp->r << " -> " << tmp->suf->l << ' ' << tmp->suf->r << '\n';
                    }
                    tmp=NULL;
                    if (nn->l+np == nn->r){
                        nn=nn->ch[a[i]-'a'];
                        np=0;
                    }
                    else if (nn->l+np < nn->r) np++;
                    // cout << " ch " << nn->l << ' ' << nn->r << ' ' << np << '\n';
                    break;
                }
            }
        }
        // cout << " => " << nn->l << ' ' << nn->r << ' ' << np << '\n';
    dfs(root,0);
    cout << mx;
    cout << '\n';
    for (int i=1;i<=n+1;i++) {
        cout << cnt[i] << ' ';
        // assert(cnt[i]==1);
    }
    cout << '\n';
    debug(root);
    // assert(sum==root->v);
}

/*
bacnmdacvvvacbvvcacvvcvabvcbavvcavcvcacbvavbcaabvccabvcabvcccabcavbcacvbcvcvacabvcbcvbcavbacbvcabvacbvcabvcabvcabvcabvcabvcabvcabvcabvcabvcabvcbvcavbbvcacbv
bacnmdacvvvacbvvcacvvcvabvcbavvcavcvcacbvavbcaabvccabvcabvcccabcavbcacvbcvcvacabv
avcvcacbvavbcaabvccabvcabvcccabcavbcacvbcvcvacabv
vcvcacbvavbcaabvccabvcabvcccabcavbcacvbcvcvacabv
bvccabvcabvcccabcavbcacvbcvcvacabv
ccabvcabvcccabcavbcacvbcvcvacabv
cabvcabvcccabcavbcacvbcvcvacabv
cabvcabvcccab
   ^   
*/