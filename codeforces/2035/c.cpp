#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        deque<int> ans;
        vector<bool> f(n+5,0);
        if (n&1){
            int tmp=n,sum=0;
            while (tmp){
                ans.emplace_back(tmp&-tmp);
                f[tmp&-tmp]=1;
                sum|=tmp&-tmp;
                if (!f[sum]) ans.emplace_back(sum);
                f[sum]=1;
                tmp-=tmp&-tmp;
            }
        }
        else{
            int cnt=0;
            while (1<<cnt <= n) cnt++;
            cnt--;
            for (int i=1;i<=cnt;i++){
                ans.emplace_back((1<<i)-1);
                f[(1<<i)-1]=1;
                ans.emplace_back(1<<i);
                f[1<<i]=1;
            }
        }
        for (int i=1;i<=n;i++){
            if (!f[i] && i&1) {
                ans.emplace_front(i);
                f[i]=1;
                break;
            }
        }
        // cout << " => " << n << '\n';
        for (int i=1;i<=n;i++) if (!f[i]) ans.emplace_front(i);
        int sum=0;
        for (int i=0;i<ans.size();i++){
            if (i&1) sum|=ans[i];
            else sum&=ans[i];
            // cout << " => " << n << ' ' << i+1 << ' ' << ans[i] << ' ' << sum << '\n';
        }
        cout << sum << '\n';
        for (auto e:ans) cout << e << ' ';
        cout << '\n';
    }
}