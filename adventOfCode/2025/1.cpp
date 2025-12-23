#include <bits/stdc++.h>
using namespace std;

int main (){
    ifstream fin;
    fin.open("1.txt");
    string s;
    long long n=50, cnt=0;
    while (fin >> s){
        int nv=0;
        for (int i=1;i<s.size();i++){
            nv=nv*10+(s[i]-'0');
        }
        // nv%=100;
        if (s[0]=='L'){
            // n-=nv;
            for (int i=0;i<nv;i++){
                n--;
                if(n<0) n=99;
                if(n==0) cnt++;
            }
        }
        else{
            // n+=nv;
            for (int i=0;i<nv;i++){
                n++;
                if(n>99) n=0;
                if(n==0) cnt++;
            }
        }
        cout << s << " " << nv << ' ' << n << " " << cnt << '\n';
    }
    cout << cnt;
}