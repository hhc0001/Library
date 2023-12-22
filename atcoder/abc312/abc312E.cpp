#include <bits/stdc++.h>
using namespace std;

int n, nmm[110][110][110], x, y, z, w, u, v;
set<int> st[100010];

int main() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> x >> z >> u >> y >> w >> v;
    for(int j = x; j < y; j++) {
      for(int k = z; k < w; k++) {
        for(int l = u; l < v; l++) {
          nmm[j][k][l] = i;
        }
      }
    }
  }
  for(int i = 0; i <= 100; i++) {
    for(int j = 0; j <= 100; j++) {
      for(int k = 0; k <= 100; k++) {
        if(nmm[i][j][k]) {
          if(i > 0 && nmm[i - 1][j][k] != nmm[i][j][k] && nmm[i - 1][j][k]) {
            st[nmm[i - 1][j][k]].insert(nmm[i][j][k]);
            st[nmm[i][j][k]].insert(nmm[i - 1][j][k]);
          }
          if(j > 0 && nmm[i][j - 1][k] != nmm[i][j][k] && nmm[i][j - 1][k]) {
            st[nmm[i][j - 1][k]].insert(nmm[i][j][k]);
            st[nmm[i][j][k]].insert(nmm[i][j - 1][k]);
          }
          if(k > 0 && nmm[i][j][k - 1] != nmm[i][j][k] && nmm[i][j][k - 1]) {
            st[nmm[i][j][k - 1]].insert(nmm[i][j][k]);
            st[nmm[i][j][k]].insert(nmm[i][j][k - 1]);
          }
        }
        //cout << i << ' ' << j << ' ' << k << ' ' << nmm[i][j][k] << '\n';
      }
    }
  }
  //cout << nmm[1][1][1] << ' ' << nmm[1][1][2] << '\n';
  for(int i = 1; i <= n; i++) {
    cout << st[i].size() << '\n';
  }
  return 0;
}