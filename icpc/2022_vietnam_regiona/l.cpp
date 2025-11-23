#include <bits/stdc++.h>
using namespace std;

mt19937 rnd;
bool b=0;

string sol1(const string &s,const int &k){
    if (k==1){
        return "OH NO!";
    }
    vector<int> a(30,0);
    deque<pair<int,int>> c[30];
    vector<char> ans;
    bool ok=1,f=0;
    for (auto e:s) a[e-'a']++;
    int p=1;
    for (int i=0;i<26;i++){
        if (!a[i]) continue;
        while (a[i]>k-1){
            while (!a[p] || p<=i) p++;
            if (p>25) {
                f=1;
                break;
            }
            for (int j=0;j<k-1;j++) ans.emplace_back(i+'a');
            ans.emplace_back(p+'a');
            a[p]--;
            a[i]-=k-1;
        }
        if (!f){
            for (int j=0;j<a[i];j++) ans.emplace_back(i+'a');
            a[i]=0;
        }
        else{
            // cout << "? " << char(i+'a') << ' ';
            // for (auto e:ans) cout << e;
            // cout << '\n';
            deque<int> dq;
            for (int j=ans.size()-1;j>=0;j--){
                if (ans[j]==i+'a'){
                    ans.pop_back();
                    a[i]++;
                    continue;
                }
                int nv=(a[i]/(k-1))+(a[i]%(k-1)!=0)-1;
                // if (nv<dq.size()){
                    //     cout << "!! " << s <<  ' ' << k <<'\n';
                    //     exit(0);
                    // }
                    assert(nv>=dq.size());
                    if (nv==dq.size()){
                        sort(dq.begin(),dq.end());
                        int x=a[i]%(k-1);
                        if (!x) x=k-1;
                        for (int jj=0;jj<x;jj++) ans.emplace_back(i+'a');
                        a[i]-=x;
                        while (a[i]){
                            ans.emplace_back(dq.front());
                            dq.pop_front();
                            for (int jj=0;jj<k-1;jj++) ans.emplace_back(i+'a');
                            a[i]-=k-1;
                        }
                        break;
                    }
                    dq.emplace_front(ans[j]);
                    ans.pop_back();
                }
                if (a[i]) ok=0;
                break;
            }
    }
    if (!ok){
        return "OH NO!";
    }
    string sans="";
    for (auto e:ans) sans+=e;
    return sans;
}

string sol2(const string &s,const int &k){
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
            ohNo=1;
            break;
        }
    }
    if (ohNo) return "OH NO!";
    return ans;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        string s="";
        int k;
        cin >> s >> k;
        // int n=rnd()%100000 + 26;
        // for (int i=0;i<n;i++) s+='a'+(rnd()%26);
        // k=rnd()%(n/26) + 2;
        // if (b) cout << n << ' ' << s << ' ' << k <<'\n';
        string ans=sol1(s,k), ans2=sol2(s,k);
        // if (b) cout << ans << '\n' << ans2 << '\n';
        if (ans!=ans2){
            assert (ans!="OH NO!");
            cout << "\n" << s << ' ' << k << '\n';
            cout << ans << '\n' << ans2 << '\n';
            exit(0);
        }
        cout << ans << '\n';
    }
}

/*
1
aaaaabbbbbbcccccc
2

1
kzmthbgssivyopnuhynfnysvnmttpiamtyeilqjtzfygeofqegkemcmnjsfbsenhjipznztsywdnaaulca
2
*/