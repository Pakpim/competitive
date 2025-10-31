#include <bits/stdc++.h>

using namespace std;

const int MxN = 1010;

struct interval_t {
    int stp, edp, idx;
    bool operator < (const interval_t& o) const {
        if(edp != o.edp) {
            return edp > o.edp;
        }
        return stp > o.stp;
    }
};

interval_t houses[MxN];
int answer[MxN];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=1; i<=n; ++i) {
        scanf("%d %d", &houses[i].stp, &houses[i].edp);
        houses[i].idx = i;
    }
    sort(houses + 1, houses + n + 1);
    int cur_day = 31, cnt = 0;
    for(int i=1; i<=n; ++i) {
        // printf("! %d\n", i);
        while(cnt >= k) {
            cur_day--;
            cnt = 0;
        }
        if(cur_day > houses[i].edp) {
            cur_day = houses[i].edp;
            cnt = 0;
        }
        cnt++;
        answer[houses[i].idx] = cur_day;
    }
    for(int i=1; i<=n; ++i) {
        cout << answer[i] << "\n";
    }
    return 0;
}