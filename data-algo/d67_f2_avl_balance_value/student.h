#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "map_avl.h"
#include <vector>

template <typename KeyT,
          typename MappedT,
          typename CompareT>
void CP::map_avl<KeyT, MappedT, CompareT>::my_recur(node* node, iterator it, std::vector<size_t> &re) const { 
    // You may need this function
    if (node==NULL) return;
    re[node->balance_value()+1]++;
    my_recur(node->left,it,re);
    my_recur(node->right,it,re);
    
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
void CP::map_avl<KeyT, MappedT, CompareT>::my_recur_2(node* node, iterator it, std::vector<size_t> &balance) const {
    // You may need this function
    // const KeyT key=it->first;
    // if (node == NULL) return NULL;
    //   int cmp = compare(key, r->data.first);
    //   if (cmp == 0) return r;
    //   parent = r;
    //   return my_recur_2(key, cmp < 0 ? r->left : r->right, parent);
    
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
std::vector<size_t> CP::map_avl<KeyT, MappedT, CompareT>::balance_values(iterator it) const  {
    // Write your code here
    std::vector<size_t> re(3,0);
    const KeyT key=it->first;
    my_recur(it.ptr,it,re);
    return re;
}

#endif