#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[100001];
int p[100001] = {};
int n;
void dfs(int i);

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  int u, v;
  for (int i = 1; i < n; i++)
  {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1);
  for (int i = 2; i <= n; i++)
    cout << p[i] << "\n";

  return 0;
}

void dfs(int i)
{
  for (int c : adj[i])
  {
    if (c == p[i]) continue;
    p[c] = i;
    dfs(c);
  }
}