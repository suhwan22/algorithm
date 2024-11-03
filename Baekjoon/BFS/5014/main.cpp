#include <iostream>
#include <queue>
#include <map>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int f, s, g, u, d;
  // f: 건물 높이, s: 출발지, g: 목적지, u: u만큼 한번에 올라가는 버튼, d: d만큼 한번에 내려가는 버튼

  cin >> f >> s >> g >> u >> d;

  if (s == g)
  {
    cout << "0";
    return 0;
  }

  bool v[1000001] = {};
  queue<pair<int, int>> q;
  q.push({s, 0});
  v[s] = true;
  pair<int, int> cur;
  int nx;
  int dx[2] = {u, -1 * d};

  while (!q.empty())
  {
    cur = q.front();
    q.pop();
    for (int i = 0; i < 2; i++)
    {
      nx = cur.first + dx[i];
      // cout << "nx: " << nx << "\n";
      if (nx < 1 || nx > f) continue;
      if (v[nx]) continue;
      if (nx == g)
      {
        cout << cur.second + 1;
        return 0;
      }
      v[nx] = true;
      q.push({nx, cur.second + 1});
    }
  }

  cout << "use the stairs";

  return 0;
}