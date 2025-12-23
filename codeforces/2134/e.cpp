#include <bits/stdc++.h>
using namespace std;

bool test=0;
vector<int> c={2,1,2,1}, bc;
mt19937 rnd;

void sw(int x){
    cout << "swap " << x << '\n';
    if (test){
        x--;
        swap(c[x], c[x+1]);
        return;
    }
    cout.flush();
}

int th(int x){
    cout << "throw " << x << '\n';
    cout.flush();
    if (test){
        int re=0;
        x--;
        while (x<c.size()){
            re++;
            x+=c[x];
        }
        cout << " => " << re << '\n';
        return re;
    }
    int re;
    cin >> re;
    return re;
}

bool answer(vector<int> &a){
    cout << "!";
    for (auto e:a) if (e) cout << ' ' << e;
    cout << '\n';
    cout.flush();
    if (test){
        bool re=1;
        for (int i=0;i<bc.size();i++) re&=bc[i]==a[i+1];
        return re;
    }
    return 1;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        if (test){
            n=rnd()%100;
            c.clear();
            for (int i=0;i<n;i++) c.emplace_back(rnd()%2+1);
            bc=c;
        }
        else cin >> n;
        vector<int> dp(n+5),ans(n+5);
        for (int i=n-1;i>0;i-=2){
            if (dp[i+2]==dp[i+3]){
                int tmp=th(i);
                if (tmp==dp[i+2]+1) ans[i]=2;
                else ans[i]=1;
                sw(i);
                tmp=th(i);
                if (tmp==dp[i+2]+1) ans[i+1]=2;
                else ans[i+1]=1;
                dp[i]=tmp;
                dp[i+1]=dp[i+2]+1;
            }
            else{
                int tmp=th(i+1);
                if (tmp==dp[i+2]+1) ans[i+1]=1;
                else ans[i+1]=2;
                sw(i);
                tmp=th(i+1);
                if (tmp==dp[i+2]+1) ans[i]=1;
                else ans[i]=2;
                dp[i+1]=tmp;
                dp[i]=dp[i+ans[i+1]]+1;
            }
        }
        if (n&1){
            if (dp[2]==dp[3]){
                sw(1);
                int tmp=th(2);
                if (tmp==dp[3]+1) ans[1]=1;
                else ans[1]=2;
            }
            else{
                int tmp=th(1);
                if (tmp==dp[2]+1) ans[1]=1;
                else ans[1]=2;
            }
        }
        if (!answer(ans)){
            cout << "wrong!\n";
            cout << n << '\n';
            for (auto e:bc) cout << e << ' '; cout << '\n';
        }
    }
}