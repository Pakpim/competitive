#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

template <typename T>
void CP::stack<T>::mitosis(int a, int b){
    int tmp=b-a+1;
    int nc=mCap*2;
    if (nc<mSize+tmp) nc=mSize+tmp;
    if (mCap<mSize+tmp) expand(nc);
    int p=mSize-1+tmp;
    for (int i=0;i<a;i++){
        mData[p--]=mData[mSize-i-1];
    }
    for (int i=a;i<=b;i++){
        mData[p--]=mData[mSize-i-1];
        mData[p--]=mData[mSize-i-1];
    }
    mSize+=tmp;
}

#endif