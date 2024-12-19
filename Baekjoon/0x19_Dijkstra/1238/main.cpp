#include <iostream>
#include <queue>
#include <algorithm>

#define INF 2147483647

using namespace std;

vector<pair<int, int>> edge[1001] = {};
vector<pair<int, int>> redge[1001] = {};
int D[1001];
int rD[1001];

int n, m, st;

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> st;
  for (int i = 0; i <= n; i++)
  {
    D[i] = INF;
    rD[i] = INF;
  }
  int u, v, w;
  for (int i = 0; i < m; i++)
  {
    cin >> u >> v >> w;
    edge[u].push_back({w, v});
    redge[v].push_back({w, u});
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  D[st] = 0;
  pq.push({0, st});
  pair<int, int> cur;
  while (!pq.empty())
  {
    cur = pq.top();
    pq.pop();
    if (cur.first > D[cur.second])
      continue;
    for (auto e : edge[cur.second])
    {
      if (D[e.second] > e.first + D[cur.second])
      {
        D[e.second] = e.first + D[cur.second];
        pq.push({D[e.second], e.second});
      }
    }
  }

  rD[st] = 0;
  pq.push({0, st});
  while (!pq.empty())
  {
    cur = pq.top();
    pq.pop();
    if (cur.first > rD[cur.second])
      continue;
    for (auto e : redge[cur.second])
    {
      if (rD[e.second] > e.first + rD[cur.second])
      {
        rD[e.second] = e.first + rD[cur.second];
        pq.push({rD[e.second], e.second});
      }
    }
  }
  int max = 0;
  for (int i = 1; i <= n; i++)
  {
    if (max < D[i] + rD[i])
      max = D[i] + rD[i];
  }
  cout << max;

  return 0;
}