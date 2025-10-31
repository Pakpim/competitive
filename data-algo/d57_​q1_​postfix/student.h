#ifndef __STUDENT_H__
#define __STUDENT_H__
#include <bits/stdc++.h>

using namespace std;

int eval_postfix(vector<pair<int, int>> v){
	stack<int> num;
	for (auto [f,s]:v){
		if (f) num.emplace(s);
		else{
			int a=num.top(); num.pop();
			int b=num.top(); num.pop();
			if (s==0) num.emplace(b+a);
			if (s==1) num.emplace(b-a);
			if (s==2) num.emplace(b*a);
			if (s==3) num.emplace(b/a);
		}
	}
	return num.top();
}

#endif
