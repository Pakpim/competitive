#include <bits/stdc++.h>
using namespace std;

mt19937 rnd;
bool b=1;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        string s;
        int k;
        cin >> s >> k;
        // int n=rnd()%20 + 5;
        // for (int i=0;i<n;i++) s+='a'+(rnd()%26);
        // k=rnd()%(n/15) + 2;
        // if (b) cout << n << ' ' << s << ' ' << k <<'\n';
        vector<int> a(30,0);
        for (auto e:s) a[e-'a']++;
        vector<pair<int,int>> v;
        int con=0;
        string ans="";
        int ohNo=0;
        for (int i=0;i<s.size();i++){
            bool f=0;
            for (int j=0;j<26;j++){
                if (!a[j]) continue;
                int nc=con;
                if (!i || ans[i-1]-'a'!=j){
                    nc=0;
                }
                nc++;
                // cout << i << ' ' << char(j+'a') << ' ' << ans << ' ' << nc << '\n';
                if (nc>=k) continue;
                a[j]--;
                bool ok=1;
                int sum=0,mx=-1,tg=-1;;
                for (int jj=0;jj<26;jj++){
                    if (a[jj]>mx){
                        mx=a[jj];
                        tg=jj;
                    }
                    sum+=a[jj];
                }
                sum-=mx;
                // cout << " => "<< i << ' ' << ans << ' ' << char(j+'a') <<  " ? " << mx/(k-1) + (mx%(k-1)!=0) -1 << ' ' << mx << ' ' << char(tg+'a') << ' ' << ' ' << sum << '\n';
                if (tg==j) mx+=nc;
                if (mx/(k-1) + (mx%(k-1)!=0) -1 >sum) ok=0;
                // cout << " => "<< i << ' ' << ans << ' ' << char(j+'a') <<  " ? " << mx/(k-1) + (mx%(k-1)!=0) -1 << ' ' << mx << ' ' << char(tg+'a') << ' ' << nc << ' ' << sum << '\n';
                if (ok){
                    f=1;
                    ans+=(j+'a');
                    con=nc;
                    break;
                }
                a[j]++;
            }
            if (!f) {
                assert(i==0);
                if (i!=0){
                    cout << "! " << s << ' ' << k << '\n';
                    cout << i << ' ' << ans << '\n';
                    exit(0);
                }
                ohNo=1;
                break;
            }
        }
        if (b){
            if (ohNo) cout << "OH NO!\n";
            else cout << ans << '\n';
        }
        if (!ohNo){
            sort(s.begin(),s.end());
            sort(ans.begin(),ans.end());
            assert(s==ans);
            if (s!=ans) cout << s << ' ' << k << "\n!=\n" << s << '\n' << ans << '\n';
            if (s!=ans) exit(0);
        }
    }
}

/*
1
nzxytozogdpzhkiklteynjuonosmbkvyefxmtwioskfmfmvawcnojnarhmheq 
5

1
lmmzxfeibnifcebsnnugzluzlizievzxfnlokzodymigext
4

1
focfff
2
*/