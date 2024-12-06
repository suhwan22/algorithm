#include <iostream>
#include <queue>

using namespace std;

int adj[1001][1001] = {};
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
      cin >> adj[i][j];
  }
  bool visit[1001] = {};
  long long cost = 0;
  visit[1] = true;
  for (int i = 1; i <= n; i++)
  {
    if (i == 1 || adj[1][i] == 0) continue;
    pq.push({adj[1][i], i});
  }
  pair<int, int> cur;
  while (!pq.empty())
  {
    cur = pq.top();
    pq.pop();
    if (visit[cur.second]) continue;
    visit[cur.second] = true;
    cost += cur.first;
    for (int i = 1; i <= n; i++)
    {
      if (i == cur.second || adj[cur.second][i] == 0 || visit[i]) continue;
      pq.push({adj[cur.second][i], i});
    }
  }
  cout << cost;

  return 0;
}