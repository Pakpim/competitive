#include <bits/stdc++.h>
using namespace std;

const int N=305;
set<pair<char,int>> s[3];
char o[N];
int v[N],a[3],x;

void play (int i){
    auto it=s[i].begin();
    cout << it->first << ' ' << it-> second << '\n'; cout.flush();
    s[i].erase(it);
    a[i]--;
    if (i==1) x^=1;
    if (i==2) x=0;
}

void rm (){
    char nc; int nv;
    cin >> nc >> nv;
    if (nc=='+' && nv&1){
        x^=1;
        s[1].erase({nc,nv});
        a[1]--;
    }
    else if (nc=='*' && (nv&1)==0){
        x=0;
        s[2].erase({nc,nv});
        a[2]--;
    }
    else{
        s[0].erase({nc,nv});
        a[0]--;
    }
}

int main (){
    int n; cin >> n;
    for (int i=0;i<n;i++){
        cin >> o[i] >> v[i];
        if (o[i]=='+' && v[i]&1) a[1]++,s[1].emplace(o[i],v[i]);
        else if (o[i]=='*' && (v[i]&1)==0) a[2]++,s[2].emplace(o[i],v[i]);
        else a[0]++,s[0].emplace(o[i],v[i]);
    }
    cin >> x; x%=2;
    if (a[2]==0){
        int tmp;
        if ((x+a[1])&1){
            cout << "me\n"; cout.flush();
            tmp=0;
        }
        else{
            cout << "you\n"; cout.flush();
            tmp=1;
        }
        for (int i=0;i<n;i++){
            if ((i&1) == tmp){
                if (a[0]) play(0);
                else if (a[1]) play(1);
            }
            else rm();
        }
    }
    else if (a[2]==1 && (a[1] & 1)){
        cout << "me\n"; cout.flush();
        for (int i=0;i<n;i++){
            if ((i&1) == 0){
                if (i==0) play(2);
                else if (a[0]) play(0);
                else play(1);
            }
            else rm();
        }
    }
    else {
        cout << "you\n"; cout.flush();
        for (int i=0;i<n;i++){
            if (i&1){
                if (a[1]&1) play(1);
                else if (a[0]) play(0);
                else if (a[2]) play(2);
                else play(1);
            }
            else rm();
        }
    }
}