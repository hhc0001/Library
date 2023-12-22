#include <bits/stdc++.h>
//#include <windows.h>
using namespace std;
using ll = long long;

struct node {
  ll d, t;
}arr[300030];

ll n, m, h, sum[300030], typ[300030], s, ans[300030];
set<pair<ll, ll>, greater<pair<ll, ll> > > dam;
set<pair<ll, ll> > AT;

signed main() {
  cin >> n >> m >> h;
  for(ll i = 1; i <= m; i++) {
    dam.insert({0, i});
  }
  for(ll i = 1; i <= n; i++) {
    cin >> arr[i].d >> arr[i].t;
    ans[i] = ans[i - 1];
    if(!typ[arr[i].t]) {
      dam.erase({sum[arr[i].t], i});
      dam.insert({(sum[arr[i].t] += arr[i].d), i});
      s += arr[i].d;
    }else {
      AT.erase({sum[arr[i].t], i});
      AT.insert({(sum[arr[i].t] += arr[i].d), i});
    }
    for(; s >= h; ) {
      AT.insert(*dam.begin());
      s -= dam.begin() -> first, ans[i]++, typ[dam.begin() -> second] = 1;
      dam.erase(dam.begin());
    }
    for(; AT.size(); ) {
      if(s + AT.begin() -> first < h) {
        dam.insert(*AT.begin()), ans[i]--, s += AT.begin() -> first, typ[AT.begin() -> second] = 0;
        AT.erase(AT.begin());
      }else {
        break;
      }
    }
  }
  for(ll i = 0; i <= m; i++) {
    cout << upper_bound(ans + 1, ans + n + 1, i) - ans - 1 << ' ';
  }
  cout << '\n';
  return 0;
}
