// Hello Junior Dev
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

// constants
const bool HAVE_CASE = false;
const ll MOD = 998244353;

// rng
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline ll getrand(ll l, ll r) {
    return uniform_int_distribution<ll>(l, r)(rng);
}

namespace nttools{
    ll pw(ll a, ll b = MOD-2, ll p = MOD) {
        if (b == 0) return 1;
        ll half = pw(a, b >> 1, p);
        ll full = (half * half) % p;
        if ((b & 1) == 0) return full;
        else return (a*full)%p;
    }

    void gen_factorial(vector<ll>& write_to, ll maxn, ll p = MOD) {
        write_to.push_back(1);
        for (ll i = 1; i <= maxn; i++) write_to.push_back((i*write_to.back())%p);
    }

    void gen_prime(vector<ll>& write_to, ll maxn) {
        bool checked[maxn+1];
        memset(checked,0,sizeof checked);
        write_to.push_back(2);
        for (ll i = 3; i <= maxn; i += 2) {
            if (!checked[i]) {
                write_to.push_back(i);
                for (ll j = 2*i; j <= maxn; j += i) checked[j] = true;
            }
        }
    }

    void gen_factor(vector<ll>& write_to, ll n) {
        vector<ll> h2;
        ll srt = floor(sqrtl(n));
        for (ll i = 1; i <= srt; i++) {
            if (n % i == 0) {
                write_to.push_back(i);
                h2.push_back(n/i);
            }
        }
        if (h2.back() == write_to.back()) h2.pop_back();
        while (!h2.empty()) {
            write_to.push_back(h2.back());
            h2.pop_back();
        }
    }

    // Miller-Rabin
    bool check_prime(ll n) {
        if (n == 1) return false;
        if (n == 2) return true;
        if (n & 2 == 0) return false;
        ll s = __builtin_ctz(n-1);
        ll d = ((n-1) >> s);

        static const ll base_list[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
        for (ll a : base_list) {
            if (a == n) return true;
            if (pw(a, d, n) == 1) continue;

            bool iteration_pass = false;
            for (ll r = 0; r < s; r++) {
                if (pw(a, d*pw(2, r, LLONG_MAX), n) == n-1) {
                    iteration_pass = true;
                    break;
                }
            }
            if (!iteration_pass) return false;
        }
        return true;
    }

    ll ncr(vector<ll> &fct_list, ll n, ll r, ll p = MOD) {
        if (n < r) return 0;
        ll top = fct_list[n];
        ll bottom = (fct_list[r]*fct_list[n-r]) % p;
        return (top * pw(bottom, p-2, p))%p;
    }
}

using namespace nttools;

struct FenwickTree{
    ll n;
    vector<ll> bit;

    FenwickTree(ll n) {
        this -> n = n+1;
        bit.assign(n+2, 0);
    }

    ll sum(ll idx) {
        idx++;
        ll ret = 0;
        while (idx > 0) {
            ret += bit[idx];
            idx -= (idx & -idx);
        }
        return ret;
    }

    ll sum(ll l, ll r) {
        return sum(r) - sum(l-1);
    }

    void add(ll idx, ll val) {
        idx++;
        while (idx <= n) {
            bit[idx] += val;
            idx += (idx & -idx);
        }
    }
};

struct segtree{
    ll n;
    vector<ll> tree;

    inline ll op(ll a, ll b) {
        return a+b;
    }

    void build(ll n) {
        this->n = n;
        tree.assign(2*n, 0);
    }

    void build(ll n, ll *a) {
        this->n = n;
        tree.assign(2*n, 0);
        for (ll i = 0; i < n; i++) tree[n+i] = a[i];
        for (ll i = n-1; i > 0; i--) tree[i] = op(tree[i<<1], tree[(i<<1)|1]);
    }

    void build(ll n, vector<ll> &a) {
        this->n = n;
        tree.assign(2*n, 0);
        for (ll i = 0; i < n; i++) tree[n+i] = a[i];
        for (ll i = n-1; i > 0; i--) tree[i] = op(tree[i<<1], tree[(i<<1)|1]);
    }

    // on interval [l, r]
    ll query(ll l, ll r) {
        r++;
        ll resl = 0, resr = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) resl = op(resl, tree[l++]);
            if (r&1) resr = op(tree[--r], resr);
        }
        return op(resl, resr);
    }

    void modify(ll p, ll val) {  // set value at position p
        for (tree[p += n] = val; p > 1; p >>= 1) tree[p>>1] = op(tree[p], tree[p^1]);
    }
};

void test_case_run() {
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    if (HAVE_CASE) cin >> t;
    while (t--) test_case_run();

    cout.flush();
    return 0;
}
