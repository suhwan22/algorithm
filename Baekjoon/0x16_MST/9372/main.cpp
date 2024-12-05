#include <iostream>
#include <queue>

using namespace std;

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  int n, m;
  while (t--)
  {
    cin >> n >> m;
    int u, v;
    vector<int> adj[1001] = {};
    for (int i = 0; i < m; i++)
    {
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    bool visit[1001] = {};
    visit[1] = true;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int u : adj[1])
      pq.push(u);
    int cur;
    int cnt = 0;
    while (!pq.empty())
    {
      cur = pq.top();
      pq.pop();
      if (visit[cur]) continue;
      visit[cur] = true;
      cnt++;
      for (int u : adj[cur])
        pq.push(u);
    }
    cout << cnt << "\n";
  }

  return 0;
}