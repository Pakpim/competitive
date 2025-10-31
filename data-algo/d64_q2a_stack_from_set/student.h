#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

//DO NOT INCLUDE ANYTHING


template <typename T>
CP::stack<T>::stack(typename std::set<T>::iterator first,typename std::set<T>::iterator last) {
  //write your code ONLY here
  mData = new T[1];
  mCap=1;
  mSize=0;
  if (first != last){
    do{
      last--;
      this->push(*last);
    }while (last!=first);
  }
}

#endif
