#include<bits/stdc++.h>

using namespace std;

using ll = long long;

const int N=305;
const int MOD=1e9+7;

int a[100010], n;
ll cnt_2[111], cnt_4[11111], cnt_44[11111];

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        cnt_2[a[i] % 100]++;
        cnt_4[a[i] % 10000]++;
    }
    for(int i=0; i<=9999; ++i) {
        cnt_44[i % 100] = max(cnt_44[i % 100], cnt_4[i]);
    }
    vector<pair<ll, int>> v;
    for(int i=0; i<=99; ++i) {
        v.emplace_back(cnt_2[i], i);
    }
    ll answer = 0ll;
    sort(v.begin(), v.end(), greater<pair<ll, int>> ());
    for(int i=0; i<=99; ++i) {
        for(int j=0; j<=99; ++j) {
            if(i == j) {
                continue;
            }
            ll cur = 0ll;
            if(cnt_2[i] > 0) {
                cur += 300000ll;
            }
            cur += 4000ll * cnt_44[j];
            int cc = 0;
            for(auto x: v) {
                if(x.second == i || x.second == j) {
                    continue;
                }
                cc++;
                cur += 500ll * x.first;
                if(cc == 3) {
                    break;
                }
            }
            answer = max(answer, cur);
        }
    }
    cout << answer << "\n";
}