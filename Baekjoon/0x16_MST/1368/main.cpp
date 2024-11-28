#include <iostream>
#include <queue>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<pair<int, int>> adj[302] = {};
bool isGroup[302] = {};

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  int n;
  int w;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> w;
    adj[i].push_back({w, n+1});
    adj[n+1].push_back({w, i});
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cin >> w;
      if (w == 0) continue;
      adj[i].push_back({w, j});
    }
  }
  isGroup[1] = true;
  for (auto p : adj[1])
    pq.push(p);
  int cnt = 1;
  int ans = 0;
  pair<int, int> cur;
  while (cnt < n + 1)
  {
    cur = pq.top();
    pq.pop();
    if (isGroup[cur.second]) continue;
    cnt++;
    ans += cur.first;
    isGroup[cur.second] = true;
    for (auto p : adj[cur.second])
      pq.push(p);
  }
  cout << ans;

  return 0;
}