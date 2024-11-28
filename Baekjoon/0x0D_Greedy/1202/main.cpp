#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

pair<int, int> jewel[300000] = {};
int bag[300000] = {};

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> jewel[i].first >> jewel[i].second;
  for (int i = 0; i < k; i++)
    cin >> bag[i];
  sort(jewel, jewel + n);
  sort(bag, bag + k);
  priority_queue<int> pq;
  int idx = 0;
  long long ans = 0;
  for (int i = 0; i < k; i++)
  {
    for (;jewel[idx].first <= bag[i] && idx < n; idx++)
      pq.push(jewel[idx].second);
    if (pq.empty()) continue;
    ans += pq.top();
    pq.pop();
  }
  cout << ans;

  return 0;
}