#include <bits/stdc++.h>
using namespace std;

const int N=200005;
int a[N],ans[N];
deque<int> dq;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=n;i>0;i--){
        ans[i]=dq.size();
        while (!dq.empty() && dq.front()<a[i]) dq.pop_front();
        dq.emplace_front(a[i]);
    }
    for (int i=1;i<=n;i++) cout << ans[i] << ' ';
}