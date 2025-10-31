#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
using ll=long long;
 
 
signed main(int argc, char *argv[]) {
	registerGen(argc, argv, 1);
	random_device rd;
    mt19937 g(rd());
    int R = opt<int> ("r");
    vector <ll> v;
    ll a=rnd.next(0,10);
    while (a<=1e9){
        v.emplace_back(a);
        if (a*2>=1e9) break;
        a=rnd.next(a*2,ll(1e9));
    }
    int N=v.size();
    int mk=1e5;
    if (N<30) mk=min(mk,1<<N);
    int K = rnd.next(1,mk+1);
	cout << N << ' ' << K << "\n";
	for(int i=0; i<N; ++i) {
		cout << v[i] << (i==N-1 ? "\n":" ");
	}
}
