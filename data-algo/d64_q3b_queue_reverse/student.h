#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <cassert>

template <typename T>
void CP::queue<T>::reverse(int a,int b) {
  //your code here
  for (int l=a,r=b;l<r;l++,r--){
    std::swap(mData[(mFront+l)%mCap],mData[(mFront+r)%mCap]);
  }
}

#endif
