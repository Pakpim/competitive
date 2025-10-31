#include <algorithm>
#include <iostream>
#include <utility>
#include <bits/stdc++.h>

#include "penguin.h"
using namespace std;

mt19937 rnd;
int count1 = 0;
std::vector<std::pair<int, int>> vpii; 
bool ask(int l1, int r1, int l2, int r2) {
  count1++;
  for (auto a : vpii)
    if ((l1 <= a.first && a.first <= r1 && l2 <= a.second && a.second <= r2) ||
        (l1 <= a.second && a.second <= r1 && l2 <= a.first && a.first <= r2))
      return true;
  return false;
}

// std::vector<std::pair<int, int>> find_couples(int n) {
//   vector<pair<int,int>> v;
// 	int l1=0;
// 	while (l1<n-1){
//     int l=l1,r=n-2,mid,tg=n;
// 		while (l<=r){
//       mid=(l+r)/2;
//       // cout << "?? " << l1 << ' ' << mid << ' ' << tg << '\n';
// 			if (ask(l1,mid,0,n-1)){
//         r=mid-1;
// 				tg=min(tg,mid);
// 			}
// 			else l=mid+1;
// 		}
//     // cout << "?" << l1 << ' ' << tg << '\n';
// 		if (tg==n) break;
// 		int r2=tg+1;
// 		while (r2<n){
//       int tg2=n;
// 			l=r2,r=n-1;
// 			while (l<=r){
//         mid=(l+r)/2;
// 				if (ask(tg,tg,r2,mid)){
//           r=mid-1;
// 					tg2=min(tg2,mid);
// 				}
// 				else l=mid+1;
// 			}
//       if (tg==3) cout << "? " << tg2 << '\n';
// 			if (tg2!=n) v.emplace_back(tg,tg2);
// 			r2=tg2+1;
// 		}
// 		l1=tg+1;
// 	}
// 	return v;
// }

signed main(int argc, char** argv) {
  int n, m;
  bool ok=1;
  do{

    std::cin >> n >> m;
    // n=rnd()%100;
    // m=rnd()%100;
    vpii.clear();
    set<pair<int,int>> s;
    // while (s.size()<m){
    //   int a=rnd()%n,b=rnd()%m;
    //   if (a>b) swap(a,b);
    //   if (a==b || s.count(make_pair(a,b))) continue;
    //   s.emplace(a,b);
    //   vpii.emplace_back(a,b);
    // }
  
    vpii.resize(m);
    for (auto& a : vpii) std::cin >> a.first >> a.second;
  
    auto res = find_couples(n);
  
    auto normalize = [&](std::vector<std::pair<int, int>>& foo) {
      for (auto& a : foo)
        if (a.first > a.second) std::swap(a.first, a.second);
      std::sort(foo.begin(), foo.end());
    };
    
    normalize(vpii), normalize(res);
    for (auto [a,b]:res) cout << " => " << a << ' ' << b << '\n';
  
    if (vpii == res) {
      ok=1;
      std::cout << "Correct. Used " << count1 << " queries." << std::endl;
    } else {
      // cout << n << ' ' << m << '\n';
      // for (auto [a,b]:vpii) cout << a << ' ' << b << '\n';
      std::cout << "Incorrect" << std::endl;
      ok=0;
    }
    break;
  }while (ok);
}
