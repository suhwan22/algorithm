#include <iostream>
#include <queue>

using namespace std;

int n, m;
vector<pair<int, int>> adj[100001];
bool isGroup[100001] = {};

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  int u, v, w;
  for (int i = 0; i < m; i++)
  {
    cin >> u >> v >> w;
    adj[u].push_back({w, v});
    adj[v].push_back({w, u});
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  isGroup[1] = true;
  for (auto p : adj[1])
    pq.push(p);
  int cnt = 1;
  long long ans = 0;
  int max = 0;
  pair<int, int> cur;
  while (cnt < n)
  {
    cur = pq.top();
    // cout << "cur: " << cur.first << ", " << cur.second << "\n";
    // cout << "cnt : " << cnt << "\n";
    pq.pop();
    if (isGroup[cur.second]) continue;
    isGroup[cur.second] = true;
    cnt++;
    ans += cur.first;
    if (cur.first > max)
      max = cur.first;
    for (auto p : adj[cur.second])
      pq.push(p);
  }
  cout << ans - max;

  return 0;
}