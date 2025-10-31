#include <bits/stdc++.h>
using namespace std;

const int N=(1<<20);
int a[N];

struct node{
    node *lc=NULL, *rc=NULL;
    int l=0,r=N-1,v=0;
    bool b=0;
    node (int l,int r):l(l), r(r){}
};

void build (node *nn){
    if (nn->l==nn->r){
        nn->v=a[nn->l];
        nn->b=1;
        return;
    }
    int mid = (nn->l+nn->r)/2;
    nn->lc = new node(nn->l,mid);
    nn->rc = new node(mid+1,nn->r);
    build(nn->lc);
    build(nn->rc);
    nn->b = !nn->lc->b;
    if (nn->b) nn->v = nn->lc->v ^ nn->rc->v;
    else nn->v = nn->lc->v | nn->rc->v;
    return;
}

void up (int p,node *nn){
    if (nn->l==nn->r){
        nn->v=a[p];
        return;
    }
    int mid=(nn->l + nn->r)/2;
    if (p<=mid) up(p,nn->lc);
    else up(p,nn->rc);
    if (nn->b) nn->v = nn->lc->v ^ nn->rc->v;
    else nn->v = nn->lc->v | nn->rc->v;
    return;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=1<<n;i++) cin >> a[i];
    node *root = new node(1,1<<n);
    build (root);
    while(m--){
        int p,b;
        cin >> p >> b;
        a[p]=b;
        up(p,root);
        cout << root->v << '\n';
    }
}