#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=4e5+5;
ll a[N];
ll n;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while (t--){
        ll sum=0;
        string s;
        cin >> n >> s;
        ll cnt=0,used=0;
        deque <ll> dq;
        for (ll i=0;i<n;i++){
            if (s[i]=='1'){
                if (cnt){
                    cnt--;
                    used++;
                    dq.emplace_back(i+1);
                }
                else{
                    if (!dq.empty()){
                        sum+=dq.front();
                        dq.pop_front();
                        dq.emplace_back(i+1);
                        if (used){
                            used--;
                            cnt++;
                        }
                    }
                    else{
                        sum+=i+1;
                        cnt++;
                    }
                }
            }
            else{
                sum+=i+1;
                cnt++;
            }
            // cout << " => " << sum << ' ' << cnt << " : ";
            // for (auto [e1,e2]:dq) cout << e1 << ',' << e2 << ' ';
            // cout << '\n';
        }

        cout << sum << '\n';
    }
}