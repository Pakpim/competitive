#include <bits/stdc++.h>
#include "penguin.h"
using namespace std;

std::vector<std::pair<int, int>> find_couples(int n) {
	vector<pair<int,int>> v;
	int l1=0;
	while (l1<n-1){
		int times = 0;
		int l=l1,r=n-2,mid,tg=n;
		if(!ask(l1, n-1, l1, n-1)) break;
		while (l<=r){
			mid=(l+r)/2; times++;
			if (ask(l1,mid,l1,n-1)){
				r=mid-1; 
				tg=min(tg,mid);
			}
			else l=mid+1;
		}
		//cout << times << '\n';
		if (tg==n) break;
		int r2=tg+1;
		while (r2<n){
			int tg2=n;
			l=r2,r=n-1;
			if(!ask(tg, tg, r2, n-1)) break;
			while (l<=r){
				mid=(l+r)/2;
				if (ask(tg,tg,r2,mid)){
					r=mid-1;
					tg2=min(tg2,mid);
				}
				else l=mid+1;
			}
			if (tg2!=n) v.emplace_back(tg,tg2);
			if (v.size()>=100) return v;
			r2=tg2+1;
		}
		l1=tg+1;
	}
	return v;
}