#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    int p=-1;
    for (int i=s.size()-1;i>=0;i--){
        if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' 
         || s[i]=='A' || s[i]=='E' || s[i]=='i' || s[i]=='O' || s[i]=='U') {
            p=i;
            break;
         }
    }
    if (p!=-1){
        for (int i=0;i<=p;i++) cout << s[i];
        // for (int i=p+2;i<s.size();i++) cout << s[i];
        cout << "ntry";
    }
    else{
        cout << s << "ntry";
    }

}