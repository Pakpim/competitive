#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
using ll=long long;
 
 
signed main(int argc, char *argv[]) {
	registerGen(argc, argv, 1);
	random_device rd;
    mt19937 g(rd());
	int N = opt<int> ("n");
    int R = opt<int> ("r");
    int mk=1e5;
    if (N<30) mk=min(mk,1<<N);
    int K = rnd.next(1,mk+1);
	cout << N << ' ' << K << "\n";
	for(int i=0; i<N; ++i) {
		int v = rnd.next(0,int(1e9+1));
		cout << v << (i==N-1 ? "\n":" ");
	}
}
