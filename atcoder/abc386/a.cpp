#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    vector<int> v(15,0);
    for (int i=0;i<4;i++){
        int a;
        cin >> a;
        v[a]++;
    }
    int c1=0,c2=0,c3=0,c4=0;
    for (int i=1;i<14;i++){
        if (v[i]!=0) c4++;
        if (v[i]==1) c1++;
        if (v[i]==2) c2++;
        if (v[i]==3) c3++;
    }
    if (c4==2 && ((c2==2) || (c3==1 && c1==1))) cout << "Yes";
    else cout << "No";
}