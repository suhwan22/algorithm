#include <iostream>
#include <queue>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<pair<int, int>> adj[10001] = {};
bool isGroup[10001] = {};

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  int v, u, w;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> v >> u >> w;
    adj[v].push_back({w, u});
    adj[u].push_back({w, v});
  }

  isGroup[1] = true;
  for (auto p : adj[1])
    pq.push(p);
  int cnt = 0;
  int ans = 0;
  pair<int, int> cur;
  while (cnt < n - 1)
  {
    cur = pq.top();
    pq.pop();
    if (isGroup[cur.second]) continue;
    isGroup[cur.second] = true;
    cnt++;
    ans += cur.first;
    for (auto p : adj[cur.second])
    {
      if (isGroup[p.second]) continue;
      pq.push(p);
    }
  }
  cout << ans;

  return 0;
}