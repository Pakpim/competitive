#include <bits/stdc++.h>

using namespace std;

const int MxN = 100010;

vector<int> adj[MxN];
bool visited[MxN], del[MxN];
int status[MxN];
stack<int> st[MxN];
vector<vector<int>> answer;

void dfs(int u) {
    status[u] = 1;
    visited[u] = true;
    for(auto v: adj[u]) {
        if(visited[v] || del[v]) {
            continue;
        }
        dfs(v);
        status[u] ^= status[v];
        if(status[v] == 1 && !del[v]) {
            while(!st[v].empty()) {
                int now = st[v].top();
                st[v].pop();
                st[u].emplace(now);
            }
        }
    }
    st[u].emplace(u);
    if(status[u] == 0) {
        answer.emplace_back(vector<int> ());
        while(!st[u].empty()) {
            int now = st[u].top();
            st[u].pop();
            if(del[now]) {
                continue;
            }
            del[now] = true;
            answer.back().emplace_back(now);
        }
    }
}

signed main(int argc, char *argv[]) {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i=1, u, v; i<=m; ++i) {
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfs(1);
    cout << answer.size() << "\n";
    for(auto a: answer) {
        cout << a.size() << " ";
        for(auto x: a) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}