#include <bits/stdc++.h>
using namespace std;

const int N=505,M=15;
int cnt[N];
bool f[N][M];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    while (n--){
        int a,b,c;
        cin >> a >> b >> c;
        if (f[a][b]){
            cout << "0\n";
            continue;
        }
        f[a][b]=1;
        if (c<240){
            cnt[a]++;
            cout << b << '\n';
            continue;
        }
        if (cnt[a]<3){
            cnt[a]++;
            cout << b << '\n';
            continue;
        }
        cout << "0\n";
    }

}