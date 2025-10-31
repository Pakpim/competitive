#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos){
	// write your code here
	int p=0,p2=0;
	for (int i=0;i<mSize;i++){
		if (p<pos.size() && i==pos[p]){
			p++;
			continue;
		}
		mData[p2++]=mData[i];
	}
	mSize-=pos.size();
}

#endif
