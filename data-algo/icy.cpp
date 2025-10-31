#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 5050;
const int INF = 1e18 + 100ll;

ll dp[MxN], a[MxN], b[MxN];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
	}
	for(int i=1; i<=k; ++i) {
		cin >> b[i];
	}
	dp[1] = a[1];
	for(int i=2; i<=n; ++i) {
		dp[i] = -INF;
		for(int j=1; j<=k; ++j) {
			if(i - k < 1) {
				continue;
			}
			dp[i] = max(dp[i], dp[i - j] + a[i] - b[j]);
		}
	}
	cout << dp[n];
	return 0;
}

/*
act as a competitive programmer. this is the problem:we have integers n,k. we have array A of size n. in each index i from 1 to n there is a value a_i. we also have another array B of size k. in each index i from 1 to k there is a value b_i. we start in position 1 and want to reach position n with a maximum cost. if we are in position i the cost will increase by a_i, we can walk to position i+1, i+2, ..., i+k. but if we go from position i to i+j the cost will decrease by b_j. we need to output a maximum cost when we reach position n.
*/