#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> adj[1001];
int n, m, start;

void BFS();
void DFS();
void dfs(int cur, bool visit[1001]);

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> start;
  int u, v;
  for (int i = 0; i < m; i++)
  {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= n; i++)
    sort(adj[i].begin(), adj[i].end());

  // for (int i = 1; i <= n; i++)
  // {
  //   sort(adj[i].begin(), adj[i].end(), greater<int>());
  // }
  // for (int i = 1; i <= n; i++)
  // {
  //   for (int j = 0; j < (int)adj[i].size(); j++)
  //     cout << adj[i][j] << " ";
  //   cout << "\n";
  // }
  DFS();

  cout << "\n";
  BFS();

  return 0;
}

void BFS()
{
  queue<int> q;
  int cur;
  bool visit[1001] = {};
  q.push(start);
  visit[start] = true;

  while (!q.empty())
  {
    cur = q.front();
    cout << cur << " ";
    q.pop();
    for (int nx : adj[cur])
    {
      if (visit[nx]) continue;
      visit[nx] = true;
      q.push(nx);
    }
  }
}

void DFS()
{
  bool visit[1001] = {};
  visit[start] = true;
  cout << start << " ";
  for (int nx : adj[start])
  {
    if (visit[nx]) continue;
    visit[nx] = true;
    dfs(nx, visit);
  }
}

void dfs(int cur, bool visit[1001])
{
  cout << cur << " ";
  for (int nx : adj[cur])
  {
    if (visit[nx]) continue;
    visit[nx] = true;
    dfs(nx, visit);
  }
}