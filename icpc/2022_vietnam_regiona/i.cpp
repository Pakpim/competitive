#include <bits/stdc++.h>
using namespace std;

const int N=1e4+5;
int n;
int a[N];

// bool t=1;
// vector<int> tp={1,4,5,2,3};
// int inv(int x,int y){
//     x--, y--;
//     swap(tp[x],tp[y]);
//     int cnt=0;
//     for (int i=0;i<tp.size();i++){
//         for (int j=i+1;j<tp.size();j++){
//             if ()
//         }
//     }
//     swap(tp[x],tp[y]);
// }

int ask (int i,int j){
    cout << "? " << i << ' ' << j << '\n';
    cout.flush();
    // if (t==1){
    //     return inv(i,j);
    // }
    int re;
    cin >> re;
    return re;
}

void ans(vector<int> v){
    cout << "!";
    for (int i=1;i<=n;i++) cout << ' ' << v[i];
    cout << '\n';
    cout.flush();
    exit(0);
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i=1;i<=n;i++){
        a[i]=ask(1,i);
    }
    vector<int> vu,vd;
    for (int i=2;i<=n;i++){
        if (a[i]>a[1]){
            int x=(a[i]-a[1]-1)/2;
            vector<int> tmp;
            for (int j=0;j<x;j++){
                tmp.emplace_back(vu[j]);
            }
            tmp.emplace_back(i);
            for (int j=x;j<vu.size();j++){
                tmp.emplace_back(vu[j]);
            }
            vu=tmp;
        }
        else{
            int x=(a[1]-a[i]-1)/2;
            vector<int> tmp;
            for (int j=0;j<x;j++){
                tmp.emplace_back(vd[j]);
            }
            tmp.emplace_back(i);
            for (int j=x;j<vd.size();j++){
                tmp.emplace_back(vd[j]);
            }
            vd=tmp;
        }
    }
    vector<int> p(n+5,0);
    p[1]=vd.size()+1;
    for (int i=0,j=vd.size();i<vd.size();i++,j--){
        p[vd[i]]=j;
    }
    for (int i=0,j=vd.size()+2;i<vu.size();i++,j++){
        // cout << " => " << i << ' ' << vu[i] << ' ' << j << '\n';
        p[vu[i]]=j;
    }
    // for (auto e:vu) cout << e << ' '; cout << '\n';
    // for (auto e:vd) cout << e << ' '; cout << '\n';
    ans(p);
}