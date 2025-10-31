#include <bits/stdc++.h>
using namespace std;

const int N=2e6+5, M=5005;
int a[N],dp[M][M];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,cnt=0,p=0;
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++){
        if (a[i]==0){
            cnt++;
            vector<int> v1,v2;
            for (int j=p+1;j<i;j++){
                if (a[j]<0) v1.emplace_back(-a[j]);
                else v2.emplace_back(a[j]);
            }
            sort(v1.begin(),v1.end());
            sort(v2.begin(),v2.end());
            int p1=0,p2=v2.size()-1;
            for (int j=0;j<=i;j++){
                while (v1[p1]<j) p1++;
                while (v2[p2]>=i-j) p2--;
                dp[i][j]=p1+p2;
            }
            p=i;
        }
    }
}