#include <bits/stdc++.h>
using namespace std;

using ll=long long;

struct node{
    node *lc=NULL, *rc=NULL;
    int cnt = 0, lv =0;
    node():lc(NULL), rc(NULL), cnt(0),lv(0) {}
};
node *root = new node();

void add (int v){
    node *nn=root;
    nn->cnt++;
    for (int i=30;i>=0;i--){
        int nv = (v>>i)&1;
        if (!nv){
            if (!nn->lc){
                nn->lc = new node();
                nn->lc->lv = i;
            }
            nn = nn->lc;
            nn->cnt++;
        }
        else{
            if (!nn->rc){
                nn->rc = new node();
                nn->rc->lv = i;
            }
            nn = nn->rc;
            nn->cnt++;
        }
    }
}

void rm (int v){
    node *nn=root;
    nn->cnt--;
    for (int i=30;i>=0;i--){
        int nv = (v>>i)&1;
        if (!nv){
            nn = nn->lc;
            nn->cnt--;
        }
        else{
            nn = nn->rc;
            nn->cnt--;
        }
    }
}



int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    add(0);
    int q;
    cin >> q;
    while (q--){
        char c;
        int v;
        cin >> c >> v;
        node *nn = root;
        if (c=='+'){
            add(v);
        }
        if (c=='-'){
            rm(v);
        }
        if (c=='?'){
            int ans = 0;
            node *nn = root;
            for (int i=30;i>=0;i--){
                int nv = (v>>i)&1;
                if (!nv){
                    if (nn->rc && nn->rc->cnt>0){
                        ans|=1<<i;
                        nn=nn->rc;
                    }
                    else{
                        nn=nn->lc;
                    }
                }
                else{
                    if (nn->lc && nn->lc->cnt>0){
                        ans|=1<<i;
                        nn=nn->lc;
                    }
                    else{
                        nn=nn->rc;
                    }
                }
            }
            cout << ans << '\n';
        }
    }
}