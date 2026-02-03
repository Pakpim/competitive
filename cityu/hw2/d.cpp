#include <bits/stdc++.h>
using namespace std;

using ll=long long;
ll cnt[35];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cnt[1]=2;
    for (int i=2;i<35;i++) cnt[i]=cnt[i-1]*2+1;
    int q;
    cin >> q;
    while (q--){
        int x, y, tg;
        cin >> y >> x;
        for (tg=1;tg<35;tg++){
            if (cnt[tg]>=y) break;
        }
        bool f=0;
        while (tg>1){
            // cout << " => " << x << ' ' << y << " : " << tg << ' ' << cnt[tg-1]+1 << '\n';
            if (y<=cnt[tg-1]){
                tg--;
                continue;
            }
            if (x<=cnt[tg-1]+1 && y-x<=cnt[tg-1]){
                f=1;
                break;
            }
            if (x>cnt[tg-1]+1) x-=cnt[tg-1]+1;
            y-=cnt[tg-1]+1;
            tg--;
        }
        if (f) cout << "blue\n";
        else cout << "red\n";
    }
}