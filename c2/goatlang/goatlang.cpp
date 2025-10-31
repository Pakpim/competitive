#include "goatlang.h"
const int M = 1e9 + 7;
using namespace std;

std::tuple<std::vector<std::vector<int>>, int, int> example1(){
    return {{{1, 0, 0}, {0, 2, 0}, {0, 0, 3}}, 2, 2};
}
std::tuple<std::vector<std::vector<int>>, int, int> example2(){
    return {{{1, 1}, {1, 0}}, 0, 1};
}

std::tuple<std::vector<std::vector<int>>, int, int>
task1(std::vector<std::vector<int>> a, int r, int c){
    for (auto &e : a)
        for (auto &f : e)
            f = (f + M) % M;
    return {a, r, c};
}

std::tuple<std::vector<std::vector<int>>, int, int>
task2(std::vector<std::vector<int>> h, int a, int b){
    int sz = h.size();
    vector<vector<int>> re = h;
    for (int i = 0; i < sz; i++)
        re[i].emplace_back(0);
    vector<int> tmp;
    for (int i = 0; i <= sz; i++)
        tmp.emplace_back(0);
    re.emplace_back(tmp);
    for (int i = 0; i < sz; i++)
        re[i][sz] = re[i][b];
    re[sz][sz] = 1;
    return {re, a, sz};
}

std::tuple<std::vector<std::vector<int>>, int, int> task3(std::vector<int> a){
    int sz=a.size();
    vector<vector<int>> re(sz+2,vector<int> (sz+2,0));
    for (int i=0;i<sz;i++){
        for (int j=i;j<sz;j++){
            if (!i && !j) re[i][j]=1;
            if (i && j) re[i][j]+=re[i-1][j-1];
            if (j) re[i][j]+=re[i][j-1];
            re[i][j]%=M;
        }
    }
    for (int i=0;i<sz;i++) re[i][sz+1]=a[i];
    for (int i=0;i<sz;i++) re[sz][sz+1]+=a[i];
    re[sz][sz+1]%=M;
    for (int i=0;i<sz;i++) re[sz][i]=(1<<i)%M;
    return {re, sz, sz+1};
}

std::tuple<std::vector<std::vector<int>>, int, int> task4()
{
    return {{{0,1,1,0,0,0,0,2},
             {0,0,0,1,1,0,0,2},
             {0,0,0,0,0,1,1,2},
             {0,0,0,1,1,0,0,2},
             {0,0,0,0,0,1,1,2},
             {0,0,0,1,0,0,0,1},
             {0,0,0,0,0,1,1,2},
             {0,0,0,0,0,0,0,0}}, 0, 7};
}

std::tuple<std::vector<std::vector<int>>, int, int> task5(std::vector<int> d){
    int sz = d.size();
    vector<vector<int>> re (sz+1, vector<int> (sz+1,0));
    for (int i=0;i<sz;i++){
        if (d[i]==1) re[i][sz]=1;
        if (i+1<sz) re[i][i+1]=1;
    }
    return {re, 0, sz};
}

std::tuple<std::vector<std::vector<int>>, int, int> task6(int m){
    vector<vector<int>> re (m+1, vector<int> (m+1,0));
    for (int i=0;i<m;i++) re[i][i+1]=1;
    re[m][1]=1;
    return {re, 0, m};
}