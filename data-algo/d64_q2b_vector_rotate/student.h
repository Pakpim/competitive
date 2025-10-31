#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::rotate(iterator first, iterator last, size_t k) {
  //write your code here
  int sz=last-first;
  T *tmp =  new T[sz];
  for (int i=0;i<sz;i++) tmp[i]=*(first+i);
  for (int i=0;i<sz;i++){
    int idx= (i+k)%sz;
    *(first+i)=tmp[idx];
  }
  delete [] tmp;
}

#endif
