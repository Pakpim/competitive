#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"

template <typename T,typename Comp >
std::vector<T> CP::priority_queue<T,Comp>::at_level(size_t k) const {
  //write your code here
  //can include anything
  std::vector<T> r;
  for (int i=(1<<k)-1;i<mSize && i<(1<<(k+1))-1;i++) r.emplace_back(mData[i]);
  // lambda [] ไม่ใช่ตัวแปรข้างนอก ex. mLess
  // [&],[=] เข้าถึงตัวแปรข้างนอกแบบต่างๆ
  std::sort(r.begin(),r.end(),[&](T a,T b){return !mLess(a,b);});
  return r;
}

#endif

