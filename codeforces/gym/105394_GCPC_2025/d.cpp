#include <bits/stdc++.h>
#define int ll
#define ll long long
#define all(x) (x).begin(), (x).end()
using namespace std;

const char nl = '\n';
const int MX = 1e5 + 3;
const int MOD = 1e9 + 7;

ll binpow(ll a, ll b=MOD-2) {
  ll res = 1;
  a=((a%MOD) +MOD)%MOD;
  for (; b; b>>=1, a=(a*a)%MOD) if (b&1) res = (res*a) %MOD;
  return res;
}

struct fenwick {
  int n;
  vector<ll> t;
  fenwick(int n) : n(n) { t.assign(n+2, 0); }
  void update(int i, ll val) {
    if (i == 0) return;
    val = ((val)%MOD +MOD)%MOD;
    for (; i <= n; i += i&-i) t[i] = (t[i] + val) % MOD;
  }
  ll query(int i) {
    ll res = 0;
    for (; i >= 1; i -= i&-i) res = (res + t[i]) % MOD;  
    return res;
  }
};

signed main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, q; double pb; cin >> n >> q >> pb;
  ll p = ((ll)(pb * 1e7) * binpow(1e7, MOD-2)) %MOD;
  fenwick up(n+3), down(n+3);
  while (q--) {
    char c; cin >> c;
    if (c == '+') {
      ll b, x; cin >> b >> x;  
      b%=MOD;
      down.update(x, (b * binpow(binpow(1-p, x), MOD-2)) % MOD);
      up.update(1, (b * binpow(1-p, x)) % MOD);
      up.update(x, (((- b+MOD)%MOD) * binpow(1-p, x)) % MOD);
    }
    if (c == '-') {
      ll b, x; cin >> b >> x;
      b%=MOD;
      down.update(x, (((- b+MOD)%MOD) * binpow(binpow(1-p, x), MOD-2)) % MOD);
      up.update(1, (((- b+MOD)%MOD) * binpow(1-p, x)) % MOD);
      up.update(x,( b * binpow(1-p, x)) % MOD);
    }
    if (c == '?') {
      int x; cin >> x;
      ll ans = (down.query(x)*binpow(1-p, x)%MOD + up.query(x)*binpow(binpow(1-p, x), MOD-2)%MOD) % MOD;
      if (ans < 0) ans += MOD;
      ans=((ans%MOD)+MOD)%MOD;
      cout << ans << nl;
    }
  }
}