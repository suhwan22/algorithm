#include <iostream>
#include <queue>

#define INF 2147483647

using namespace std;

int D[1001] = {};
int start;
int dest;

vector<pair<int, int>> line[1001] = {};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    D[i] = INF;

  int v, u, w;
  for (int i = 0; i < m; i++)
  {
    cin >> v >> u >> w;
    line[v].push_back({w, u});
  }
  cin >> start >> dest;
  D[start] = 0;

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({D[start], start});
  
  pair<int, int> cur;
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

  cout << D[dest];

  return 0;
}