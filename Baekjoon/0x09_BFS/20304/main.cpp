#include <iostream>
#include <queue>

using namespace std;

bool vis[1000001] = {};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  int p;
  queue<pair<int, int>> q;
  for (int i = 0; i < m; i++)
  {
    cin >> p;
    vis[p] = true;
    q.push({p, 0});
  }

  int bitSize = 0;
  while (n / (1 << ++bitSize)) {}

  pair<int, int> cur;
  int nx;
  int max = -1;
  while (!q.empty())
  {
    cur = q.front();
    q.pop();
    if (cur.second > max)
      max = cur.second;
    for (int i = 0; i <= bitSize; i++)
    {
      nx = cur.first ^ (1 << i);
      if (nx > n || vis[nx]) continue;
      vis[nx] = true;
      q.push({nx, cur.second + 1});
    }
  }

  cout << max;

  return 0;
}