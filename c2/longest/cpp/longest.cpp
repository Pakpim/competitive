#include "longest.h"
#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> longest(int n) {

    vector<pair<int,int>> ans;
    int a=0,b=1;
    ans.emplace_back(0,0);
    ans.emplace_back(0,1);
    if (n==2) return ans;
    if (find(0,1,2)) a=0,b=2;
    else a=1,b=2;
    ans.emplace_back(a,b);
    for (int i=3;i<n;i++){
        if (find(a,b,i)){
            
        }
        else{

        }
    }
    return ans;
}