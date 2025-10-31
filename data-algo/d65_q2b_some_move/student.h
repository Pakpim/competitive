#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector-sm.h"
#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
void CP::vector_some_move<T>::insert(int index, std::vector<T> &value){
	// Your code here
	mSize+=value.size();
	mCap+=value.size();
	if (mData.empty()){
		mData.push_back(value);
		aux.emplace_back(value.size());
		return;
	}
	int i = std::upper_bound(aux.begin(), aux.end(), index) - aux.begin();
	if (i==mData.size()) i--;
	int j = index;
	if (i) j -= aux[i-1];
	mData[i].insert(mData[i].begin()+j,value.begin(),value.end());
	for (int k=i;k<aux.size();k++) aux[k]+=value.size();
	if (mData[i].size()>1733){
		int mid=(mData[i].size())/2;
		mData.insert(mData.begin()+i+1,std::vector<T> (mData[i].begin()+mid,mData[i].end()));
		aux.insert(aux.begin()+i,mid);
		if (i) aux[i]+=aux[i-1];
		mData[i].erase(mData[i].begin()+mid,mData[i].end());
	}
}

#endif
