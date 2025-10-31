#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>

template <typename T>
template <typename Comp>
T CP::queue<T>::min_element(std::vector<size_t> pos,Comp comp) const {
  //your code here
  T re;
  for (auto e:pos) if (e<size()) re= mData[(mFront+e) % mCap];
  for (auto e:pos) if (e<size() && comp(mData[(mFront+e) % mCap],re)) re= mData[(mFront+e) % mCap];
  //should return something
  return re;
}

#endif
