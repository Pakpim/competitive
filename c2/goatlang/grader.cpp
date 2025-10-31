#include "goatlang.h"
#include <functional>
#include <iostream>
#include <string>
using namespace std;

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
    for (auto e1:re){
      cout << "\n => ";
      for (auto e2:e1) cout << e2 << ' ';
    }
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
    for (auto e1:re){
      cout << "\n => ";
      for (auto e2:e1) cout << e2 << ' ';
    }
    return {re, 0, sz};
}
std::tuple<std::vector<std::vector<int>>, int, int> task6(int m){
    vector<vector<int>> re (m+1, vector<int> (m+1,0));
    for (int i=0;i<m;i++) re[i][i+1]=1;
    re[m][1]=1;
    return {re, 0, m};
}

vector<vector<int>> id(int n) {
  vector<vector<int>> ret;
  for (int i = 0; i < n; i++) {
    vector<int> row;
    row.resize(n, 0);
    row[i] = 1;
    ret.push_back(row);
  }
  return ret;
}
bool sanitize(vector<vector<int>> &A, int in, int out) {
  int n = A.size();
  if (n > 40)
    return false;
  if (in < 0 || in >= n)
    return false;
  if (out < 0 || out >= n)
    return false;
  for (int i = 0; i < n; i++) {
    if (A[i].size() != n)
      return false;
    for (int j = 0; j < n; j++) {
      if (A[i][j] < 0)
        return false;
      A[i][j] %= 1000000007;
    }
  }
  return true;
}
vector<vector<int>> matmul(vector<vector<int>> A, vector<vector<int>> B) {
  vector<vector<int>> prod = A;
  int n = A.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      prod[i][j] = 0;
      for (int k = 0; k < n; k++) {
        prod[i][j] += 1ll * A[i][k] * B[k][j] % 1000000007;
        prod[i][j] %= 1000000007;
      }
    }
  }
  return prod;
}
int main() {
  string task;
  cin >> task;
  function<tuple<vector<vector<int>>, int, int>()> f;
  int lim = 100;
  if (task == "example1") {
    f = example1;
  } else if (task == "example2") {
    f = example2;
  } else if (task == "task1" || task == "task2") {
    int N, r, c;
    cin >> N >> r >> c;
    vector<vector<int>> A;
    for (int i = 0; i < N; i++) {
      vector<int> row;
      row.reserve(N);
      for (int j = 0; j < N; j++) {
        int x;
        cin >> x;
        row.push_back(x);
      }
      A.push_back(row);
    }
    auto inner = task == "task1" ? task1 : task2;
    f = [A, r, c, inner]() { return inner(A, r, c); };
  } else if (task == "task3") {
    int D;
    cin >> D;
    vector<int> coeffs;
    coeffs.reserve(D + 1);
    for (int i = 0; i <= D; i++) {
      int x;
      cin >> x;
      coeffs.push_back(x);
    }
    f = [coeffs]() { return task3(coeffs); };
  } else if (task == "task4") {
    f = task4;
  } else if (task == "task5") {
    string bs;
    cin >> bs;
    vector<int> bsinp;
    bsinp.reserve(bs.size());
    lim = bs.size();
    for (int i = 0; i < bs.size(); i++)
      bsinp.push_back(bs[i] == '1' ? 1 : 0);
    f = [bsinp]() { return task5(bsinp); };
  } else if (task == "task6") {
    int m;
    cin >> m;
    f = [m]() { return task6(m); };
  } else {
    cerr << "Unknown task. Exiting." << endl;
    exit(1);
  }
  auto prog = f();
  vector<vector<int>> mat, cur;
  int iidx, jidx;
  tie(mat, iidx, jidx) = prog;
  if (!sanitize(mat, iidx, jidx)) {
    cerr << "Invalid return value. Exiting." << endl;
    exit(1);
  }
  cur = id(mat.size());
  for (int n = 1; n <= lim; n++) {
    cur = matmul(cur, mat);
    cout << "n = " << n << " gives " << cur[iidx][jidx] << endl;
  }
  return 0;
}

/*
task3
5
1 1 1 1 1 1

task4

task5
1010101001

task6
9
*/