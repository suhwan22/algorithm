#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

void output(int idx, int cnt);

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  queue<pair<int, int>> q;
  int idx = 0;
  while (++idx)
  {
    int n, m;
    cin >> n >> m;
    if (n == 0 && m == 0)
      break;
    int u, v;
    vector<int> adj[501] = {};
    for (int i = 0; i < m; i++)
    {
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    int cnt = 0;
    bool visit[501] = {};
    for (int i = 1; i <= n; i++)
    {
      if (visit[i]) continue;
      visit[i] = true;
      bool flag = true;
      pair<int, int> cur;
      q.push({i, -1});
      while (!q.empty())
      {
        cur = q.front();
        q.pop();
        for (int v : adj[cur.first])
        {
          if (v == cur.second) continue;
          if (visit[v])
          {
            flag = false;
            continue;
          }
          visit[v] = true;
          q.push({v, cur.first});
        }
      }
      if (flag)
        cnt++;
    }
    output(idx, cnt);
  }

  return 0;
}

void output(int idx, int cnt)
{
  if (cnt == 0)
    cout << "Case " << idx << ": No trees.\n";
  else if (cnt == 1)
    cout << "Case " << idx << ": There is one tree.\n";
  else
    cout << "Case " << idx << ": A forest of " << cnt << " trees.\n";
}