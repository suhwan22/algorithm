#include <iostream>
#include <queue>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  pair<long long, long long> cur;

  long long n, m;
  cin >> n >> m;

  // n -> m
  // n*2 or n*10 + 1;
  //
  queue<pair<long long, long long>> q;
  q.push({n, 0});
  long long nx;
  long long min = 0x7fffffff;
  while (!q.empty())
  {
    cur = q.front();
    q.pop();
    nx = cur.first * 2;
    if (nx <= m)
    {
      if (nx == m)
      {
        if (min > cur.second + 1)
          min = cur.second + 1;
      }
      else
        q.push({nx, cur.second + 1});
    }
    nx = cur.first * 10 + 1;
    if (nx <= m)
    {
      if (nx == m)
      {
        if (min > cur.second + 1)
          min = cur.second + 1;
      }
      else
        q.push({nx, cur.second + 1});
    }
  }
  if (min == 0x7fffffff)
    cout << -1;
  else
    cout << min + 1;

  return 0;
}