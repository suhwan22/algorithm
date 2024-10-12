#include <iostream>
#include <queue>

using namespace std;

#define INF 2147483647

int D[1001] = {};
int pre[1001] = {};

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
  int start, dest;
  cin >> start >> dest;

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  D[start] = 0;
  pair<int, int> cur;
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
        pre[line[cur.second][i].second] = cur.second;
      }
    }
  }

  vector<int> path;
  int city = dest;
  while (1)
  {
    path.push_back(city);
    if (city == start)
      break;
    city = pre[city];
  }
  cout << D[dest] << "\n" << path.size() << "\n";
  while (!path.empty())
  {
    cout << path.back() << " ";
    path.pop_back();
  }

  return 0;
}