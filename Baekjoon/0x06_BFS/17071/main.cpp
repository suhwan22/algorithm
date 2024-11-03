#include <iostream>
#include <queue>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  queue<pair<int, int>> q;
  pair<int, int> cur;
  bool visit[2][500001] = {};
  int dx[2] = {-1, 1};
  int nx;

  q.push({n, 0});
  visit[0][n] = true;
  q.push({m, -1});

  while (!q.empty())
  {
    cur = q.front();
    q.pop();
    if (cur.second < 0)
    {
      if (visit[(-1 * cur.second - 1) % 2][m])
      {
        cout << -1 * cur.second - 1;
        return 0; 
      }
      m = cur.first - cur.second;
      if (m > 500000)
      {
        cout << -1;
        return 0;
      }
      q.push({m, cur.second - 1});
    }
    else
    {
      for (int i = 0; i < 2; i++)
      {
        nx = cur.first + dx[i];
        if (nx < 0 || nx > 500000) continue;
        if (visit[(cur.second + 1) % 2][nx]) continue;
        visit[(cur.second + 1) % 2][nx] = true;
        q.push({nx, cur.second + 1});
      }
      nx = cur.first * 2;
      if (nx < 0 || nx > 500000) continue;
      if (visit[(cur.second + 1) % 2][nx]) continue;
      visit[(cur.second + 1) % 2][nx] = true;
      q.push({nx, cur.second + 1});
    }
  }

  cout << -1;

  return 0;
}