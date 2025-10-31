#include <bits/stdc++.h>
using namespace std;

using ll=long long;
mt19937 rnd;

struct node{
    ll prio,l,r,cnt=1,sum,idx;
    node *lc=NULL,*rc=NULL,*par=NULL;
    node(ll l,ll r) : prio(rnd()),l(l),r(r),sum(r-l+1) {}
    ll sz(){ return r-l+1; }
    ll idx(){
        
    }
};

map<ll,node*> mp;

node* mg (node* t1,node* t2){
    if (!t1) return t2;
    if (!t2) return t1;
    if (t2->prio < t1->prio){
        t1->cnt += t2->cnt;
        t1->sum += t2->sum;
        t1->rc = mg(t1->rc,t2);
        // t1->rc->idx 
        return t1;
    }
    else{
        t2->cnt += t1->cnt;
        t2->sum += t1->sum;
        t2->idx += t1->sum;
        t2->lc=mg(t1,t2->lc);
        return t2;
    }
}

void sp (node* nn,node* &l,node* &r,int x){
    if (!nn) return;
    if (nn->idx<=x){
        l=nn;
        node* tg=nn->rc;
        if (nn->rc) nn->cnt -= nn->rc->cnt, nn->sum -= nn->rc->sum;
        nn->rc=NULL;
        if (tg && tg->lc) idx+=tg->lc->cnt;
        sp(tg,l->rc,r,x,idx);
        l->cnt += l->rc->cnt;
    }
    else{
        r=nn;
        node* tg=nn->lc;
        if (nn->lc) nn->cnt -= nn->lc->cnt, nn->sum -= nn->lc->sum;
        nn->lc=NULL;
        idx--;
        if(tg && tg->rc) idx-=tg->rc->cnt;
        sp(tg,l,r->lc,x,idx);
        r->cnt += r->lc->cnt;
    }
    return;
}

void del (node *nn){
    if (!nn) return;
    del(nn->lc);
    del(nn->rc);
    mp.erase(nn->r);
    free(nn);
}

ll qu (ll tg, node* nn, int nsum){
    if (nsum < tg && nsum + nn->sz() > tg){
        return nn->l + tg-nsum;
    }
    if (nsum < tg){
        nsum+=nn->sz();
        if (nn->rc->lc) nsum+=nn->rc->lc->sum;
        return qu(tg, nn->rc, nsum);
    }
    else{
        nsum-=nn->lc->sz();
        if (nn->lc->rc) nsum-=nn->lc->rc->sum;
        return qu(tg, nn->lc, nsum);
    }
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int q;
    cin >> q;
    ll sum=0;
    node *rt = new node(0,0);
    while (q--){
        int p, k;
        cin >> p >> k;
        node* tgn = mp.lower_bound(p)->second;
        int idx = tgn->left;
        if (k<0){
            
        }
        else{

        }
        cout << qu(rt->sum/2 + rt->sum%2,rt,rt->lc->sum) << '\n';
    }
}