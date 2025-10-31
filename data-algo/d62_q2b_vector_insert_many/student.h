#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int, T>> data){
	// write your code here
	sort(data.begin(),data.end());
	T *tmp = new T[mSize];
	int bs=mSize;
	for (int i=0;i<mSize;i++) tmp[i]=mData[i];
	resize(mSize+data.size());
	int p=0,i=0;
	for (auto &[a,b]:data){
		while (p<a) mData[i++]=tmp[p++];
		mData[i++]=b;
	}
	while (p<bs) mData[i++]=tmp[p++];
	delete [] tmp;
}

#endif
