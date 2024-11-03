#include <iostream>
#include <stack>

using namespace std;

int adj[1001][1001] = {};
bool vis[1001] = {};
int n, m;

void dfs(int i);

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  int u, v;
  for (int i = 0; i < m; i++)
  {
    cin >> u >> v;
    adj[u][v] = 1;
    adj[v][u] = 1;
  }

  int cnt = 0;
  for (int i = 1; i <= n; i++)
  {
    if (vis[i] == false)
    {
      cnt++;
      dfs(i);
    }
  }
  cout << cnt;

  return 0;
}

void dfs(int i)
{
  stack<int> s;
  s.push(i);
  vis[i] = true;
  int cur;
  while (!s.empty())
  {
    cur = s.top();
    s.pop();
    for (int j = 1; j <= n; j++)
    {
      if (vis[j] == false && adj[cur][j] == 1)
      {
        vis[j] = true;
        s.push(j);
      }
    }
  }
}