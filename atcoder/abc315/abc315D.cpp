#include <bits/stdc++.h>
using namespace std;

int h, w, sl[2020][256], sc[2020][256], ans;
char c[2020][2020];

void del(int x, int y, int z, int w) {
  for(int i = x; i <= y; i++) {
    for(int j = z; j <= w; j++) {
      sl[i][c[i][j]]--, sc[j][c[i][j]]--;
      c[i][j] = '.';
      sl[i][c[i][j]]++, sc[j][c[i][j]]++;
    }
  }
}

int main() {
  cin >> h >> w;
  for(int i = 1; i <= h; i++) {
    for(int j = 1; j <= w; j++) {
      cin >> c[i][j];
      sl[i][c[i][j]]++;
      sc[j][c[i][j]]++;
    }
  }
  //cout << '\n';
  for(int i = 1; i <= 5000; i++) {
    vector<int> lj, lk;
    for(int j = 1; j <= h; j++) {
      int cnt = 0, cnt2 = 0;
      for(int k = 'a'; k <= 'z'; k++) {
        cnt += !!sl[j][k], cnt2 += sl[j][k];
      }
      if(cnt == 1 && cnt2 > 1) {
        lj.push_back(j);
      }
    }
    for(int j = 1; j <= w; j++) {
      int cnt = 0, cnt2 = 0;
      for(int k = 'a'; k <= 'z'; k++) {
        cnt += !!sc[j][k], cnt2 += sc[j][k];
      }
      if(cnt == 1 && cnt2 > 1) {
        lk.push_back(j);
      }
    }
    for(auto j : lj) {
      del(j, j, 1, w);
    }
    for(auto j : lk) {
      del(1, h, j, j);
    }
    //for(int j = 1; j <= h; j++) {
      //for(int k = 1; k <= w; k++) {
        //cout << c[j][k];
      //}
      //cout << '\n';
    //}
    //cout << '\n';
  }
  for(int i = 1; i <= h; i++) {
    for(int j = 1; j <= w; j++) {
      ans += c[i][j] != '.';
    }
  }
  cout << ans << '\n';
  return 0;
}