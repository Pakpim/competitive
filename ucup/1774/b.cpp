#include<bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        bool ok=1;
        int n,l;
        int cnt=0;
        vector<tuple<int,int,int>> v; // ns 2=l 1=r 0=no
        cin >> n >> l;
        for (int i=0;i<n;i++){
            int a,b;
            cin >> a >> b;
            if (a==-1 && b==-1) cnt++;
            else if (a==-1){
                v.emplace_back(b,b,2);
            }
            else if (b==-1){
                v.emplace_back(a,a,1);
            }
            else v.emplace_back(a,b,0);
        }
        int cnt2=0,cnt3=0;
        if (!v.empty()){
            sort(v.begin(),v.end());
            auto [l1,r1,s1]=v[0];
            int br=r1,bs=s1; // cnt2==must cnt3==can
            if (l1!=1 && s1!=2) cnt2++,cnt3+=l1-2;
            else if (l1!=1) cnt3+=l1-1;
            for (int i=1;i<v.size();i++){
                auto [nl,nr,ns]=v[i];
                if (nl<=br){
                    ok=0;
                    break;
                }
                if (nl!=br+1 && bs!=1 && ns!=2) cnt2++,cnt3+=nl-br-2;
                else if (nl-br>1) cnt3+=nl-br-1;
                br=nr;
                bs=ns;
            }
            auto [ln,rn,sn]=v[v.size()-1];
            if (rn!=l && sn!=1) cnt2++,cnt3+=l-rn-1;
            else if (rn!=l) cnt3+=l-rn;
        }
        else{
            cnt2=1;
            cnt3=l-1;
        }
        if (cnt<cnt2 || (cnt-cnt2)>cnt3) ok=0;
        if (ok) cout << "TAK\n";
        else cout << "NIE\n";
    }
}