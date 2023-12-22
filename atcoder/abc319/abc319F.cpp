#include <bits/stdc++.h>
using namespace std;

struct node {
  int pa, t, s, g;
  vector<int> ch;
}arr[550];

int n, dp[2048], cnt, num[11], visib[2048][11];
priority_queue<pair<pair<int, int>, int> > pq[2048];

int main() {
  cin >> n;
  for(int i = 2; i <= n; i++) {
    cin >> arr[i].pa >> arr[i].t >> arr[i].s >> arr[i].g;
    arr[arr[i].pa].ch.push_back(i);
    if(arr[i].t == 2) {
      num[cnt++] = i;
    }
    if(arr[i].pa == 1 && arr[i].t == 1) {
      pq[0].push({{arr[i].s, arr[i].g}, i});
    }
  }
  for(int i = 0; i < (1 << cnt); i++) {
  }
  return 0;
}