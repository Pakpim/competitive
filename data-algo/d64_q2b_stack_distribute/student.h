#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
std::vector<std::vector<T>> CP::stack<T>::distribute(size_t k) const{
    // write your code here
    std::vector<std::vector<T>> re(k);
    int p=mSize;
    for (int i=0;i<k;i++){
        int ns=mSize/k;
        if (i<mSize%k) ns++;
        for (int j=0;j<ns;j++) re[i].emplace_back(mData[--p]);
    }
    return re;
}
#endif
