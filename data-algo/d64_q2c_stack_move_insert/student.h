#ifndef __STUDENT_H__
#define __STUDENT_H__
#include <bits/stdc++.h>

template <typename T>
void CP::stack<T>::moveInsert(int k,CP::stack<T> &s2, int m) {
  //your code here
  k=std::min(k,int(mSize));
  m=std::min(m,int(s2.size()));
  expand(std::max(mCap*2,m+mSize));
  for (int i=0;i<k;i++){
    mData[mSize-i-1+m]=mData[mSize-i-1];
  }
  mSize+=m;
  int p=mSize-1-k;
  while (!s2.empty() && m){
    int nv=s2.top();
    s2.pop();
    mData[p--]=nv;
    m--;
  }
}
#endif
