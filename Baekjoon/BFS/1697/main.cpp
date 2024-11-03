#include <iostream>
#include <queue>
#include <map>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  if (n == m)
  {
    cout << 0;
    return 0;
  }

  // n -> m 되는 최소 시간

  bool v[100001] = {};
  queue<pair<int, int>> q;
  pair<int, int> cur;
  int x1;
  int x2;
  int x3;
  q.push({n, 1});
  v[n] = true;
  while (!q.empty())
  {
    cur = q.front();
    q.pop();
    x1 = cur.first - 1;
    x2 = cur.first + 1;
    x3 = cur.first * 2;
    if (x1 < 0 || x1 > 100000 || v[x1] == true);
    else
    {
      if (x1 == m)
      {
        cout << cur.second;
        return 0;
      }
      v[x1] = true;
      q.push({x1, cur.second + 1});
    }
    if (x2 < 0 || x2 > 100000 || v[x2] == true);
    else
    {
      if (x2 == m)
      {
        cout << cur.second;
        return 0;
      }
      v[x2] = true;
      q.push({x2, cur.second + 1});

    }
    if (x3 < 0 || x3 > 100000 || v[x3] == true);
    else
    {
      if (x3 == m)
      {
        cout << cur.second;
        return 0;
      }
      v[x3] = true;
      q.push({x3, cur.second + 1});
    }
  }

  return 0;
}