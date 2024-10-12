#include <iostream>
#include <queue>

using namespace std;

#define INF 2147483647

int start;
int V, E;
int D[20001] = {};
vector<pair<int, int>> line[20001] = {};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> V >> E >> start;

  for (int i = 0; i <= V; i++)
    D[i] = INF;

  // pair{거리, 정점}
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pair<int, int> cur;
  int u, v, w;
  for (int i = 0; i < E; i++)
  {
    cin >> u >> v >> w;
    line[u].push_back({w, v});
  }
  D[start] = 0;

  pq.push({D[start], start});
  while (!pq.empty())
  {
    cur = pq.top();
    pq.pop();
    if (cur.first > D[cur.second]) continue;
    for (int i = 0; i < (int)line[cur.second].size(); i++)
    {
      if (D[line[cur.second][i].second] > cur.first + line[cur.second][i].first)
      {
        D[line[cur.second][i].second] = cur.first + line[cur.second][i].first;
        pq.push({D[line[cur.second][i].second], line[cur.second][i].second});
      }
    }
  }
  for (int i = 1; i <= V; i++)
  {
    if (D[i] == INF)
      cout << "INF\n";
    else
      cout << D[i] << "\n";
  }

  return 0;
}