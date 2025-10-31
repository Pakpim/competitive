#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "list.h"

template <typename T>
void CP::list<T>::block_swap(iterator a1, iterator a2, iterator b1, iterator b2) {
	// write your code here
	if (b2==a1){
		std::swap(a1,b1);
		std::swap(a2,b2);
	}
	if (a2==b1){
		node* t = a2.ptr->prev;
		a1.ptr->prev->next = b1.ptr;
		b1.ptr->prev=a1.ptr.prev;
		
		return;
	}
	std::swap(a1.ptr->prev->next,b1.ptr->prev->next);
	std::swap(a1.ptr->prev,b1.ptr->prev);
	std::swap(a2.ptr->prev->next,b2.ptr->prev->next);
	std::swap(a2.ptr->prev,b2.ptr->prev);
}

#endif
