#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::mirror() {
  //write your code here
  ensureCapacity(mSize*2);
  for (int i=0;i<mSize;i++){
    mData[mSize*2-1-i]=mData[i];
  }
  mSize*=2;
}

#endif
