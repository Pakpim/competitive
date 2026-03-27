#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int a[N],b[N],c[N], val[N*6], ora[4][4]={{0,2,1,0},
                                         {2,1,0,1},
                                         {1,0,2,2},
                                         {0,1,2,3}};
vector<tuple<char,int,int>> v;
char cha[4]={'R','G','B','*'};

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int cnt=n;
    a[n]=n;
    for (int i=n-1;i>0;i--){
        v.emplace_back('|',i,a[i+1]);
        cnt++;
        v.emplace_back('|',cnt,a[i+1]);
        cnt++;
        a[i]=cnt;
    }
    b[1]=a[1];
    for (int i=2;i<=n;i++){
        v.emplace_back('&',b[i-1],a[i]);
        cnt++;
        b[i]=cnt;
    }
    for (int i=2;i<=n;i++){
        v.emplace_back('|',a[i],b[i-1]);
        cnt++;
        c[i]=cnt;
    }
    v.emplace_back('|',a[1],a[1]);
    cnt++;
    for (int i=2;i<=n;i++){
        v.emplace_back('|',cnt,a[i]);
        cnt++;
        v.emplace_back('|',cnt,c[i]);
        cnt++;
    }
    cout << v.size() << '\n';
    for (auto [t,l,r]:v) cout << t << ' ' << l << ' ' << r << '\n';
    assert(v.size()<=n*6);
    // for (int i=0;i<1<<(n*2);i++){
    //     int k=i, tg=-1,nc=0;
    //     vector<bool> fg(5,0);
    //     for (int j=0;j<n;j++, k>>=2){
    //         val[j+1]=k%4;
    //         if (fg[k%4] || k%4==3) continue;
    //         fg[k%4]=1;
    //         nc++;
    //         if (nc==3) tg=k%4;
    //     }
    //     if (tg==-1) continue;
    //     cnt=n+1;
    //     for (auto [t,l,r]:v){
    //         if (t=='|'){
    //             if (val[l]==val[r]) val[cnt]=val[l];
    //             else if (val[l]==3) val[cnt]=val[r];
    //             else if (val[r]==3) val[cnt]=val[l];
    //             else val[cnt]=(6-val[l]-val[r])%3;
    //         }
    //         else{
    //             val[cnt]= (val[l]==val[r]? val[l]:3);
    //         }
    //         cnt++;
    //     }
    //     if (val[v.size()+n]!=tg){
    //         cout << " wrong ";
    //         for (int i=1;i<=n;i++) cout << cha[val[i]] << ' ';
    //         cout << " : ";
    //         for (int i=1;i<=n;i++) cout << cha[val[a[i]]] << ' ';
    //         cout << '\n';
    //     }
    // }
}