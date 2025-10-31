#include <bits/stdc++.h>
using namespace std;

const int N=502;
int mn[N][N],dp[N][N],bt[N][N][3];

void ch (const string &s){
    string re="";
    for (int i=0;i<s.size()-1;i+=2){
        if (s[i]=='0') re+=s[i+1];
        else{
            for (int j=0;j<s[i+1]-'0';j++){
                if (re.size()<s[i]-'0'){
                    // cout << "\nerror\n";
                    return;
                }
                re+=re[re.size()-(s[i]-'0')];
            }
        }
    }
    // cout << "\ncheck : " << re.size() << ' ' << re  << '\n';
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    string s; 
    cin >> s;
    for (auto &e:s) e-='0';
    int n=s.size();
    for (int i=0;i<=n;i++) for (int j=0;j<=n;j++) dp[i][j]=1e9,bt[i][j][0]=100;
    dp[0][0]=0;
    for (int i=0;i<=n;i++){
        for (int j=0;j<=n;j++){
            if (dp[i][j]==1e9) continue;
            // // cout << i << ' ' << j << " = " << dp[i][j] << '\n';
            for (int k=0;k<100;k++){
                int a=k/10, l=k%10, ti,tj;
                if (a==0 || l==0){
                    if (a==0 && l==0){
                        if (s[i]!=l || s[n-1-j]!=a) continue;
                        ti=i+1;
                        tj=j+1;
                    }
                    else if (a==0){
                        if (s[i]!=l) continue;
                        ti=i+1;
                        tj=j;
                    }
                    else{
                        if (s[n-1-j]!=a) continue;
                        ti=i;
                        tj=j+1;
                    }
                }
                else{
                    if (a>i || l>n-j-a || i+l>n || j+a>n) continue;
                    bool ok=1;
                    for (int np=0;np<l;np++) {
                        if (s[i+np]!=s[i+np-a]) ok=0;
                    }
                    for (int np=0;np<a;np++) {
                        if (s[n-1-j-np]!=s[n-1-j-np-l]) ok=0;
                    }
                    if (!ok) continue;
                    ti=i+l;
                    tj=j+a;
                }
                if (dp[ti][tj] >= dp[i][j]+1){
                    if (dp[ti][tj]==dp[i][j]+1 && bt[ti][tj][0]<l*10+a) continue;
                    dp[ti][tj]=dp[i][j]+1;
                    bt[ti][tj][0]=l*10+a;
                    bt[ti][tj][1]=i;
                    bt[ti][tj][2]=j;
                }
            }
        }
    }
    string ans="";
    deque<int> dq;
    int i=n,j=n;
    while (i || j){
        int l=bt[i][j][0]/10, a=bt[i][j][0]%10;
        // cout << i << ' ' << j << " = " << a << l << '\n';
        dq.emplace_front(l);
        dq.emplace_front(a);
        int xi=bt[i][j][1], xj=bt[i][j][2];
        i=xi; j=xj;
    }
    for (auto e:dq) ans+=char(e+'0');
    // cout << dp[n][n] << ' ';
    // ch(ans);
    reverse(ans.begin(),ans.end());
    // ch(ans);
    cout << ans;
}
    