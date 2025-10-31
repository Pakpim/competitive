#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
  //write your code here
  int pos=position-begin();
  int bs=mSize;
  int sz=last-first;
  resize(mSize+sz);
  for (int i=bs-1;i>=pos;i--){
    mData[i+sz]=mData[i];
  }
  for (int i=0;i<sz;i++){
    mData[pos+i]=*(first+i);
  }
}

#endif
