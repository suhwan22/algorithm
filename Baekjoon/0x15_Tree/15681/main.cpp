#include <iostream>
#include <vector>

using namespace std;

vector<int> edge[100001] = {};
int D[100001] = {};
bool vis[100001] = {};
int n, r, q;

int subTree(int root);

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> r >> q;
  int u, v;
  for (int i = 0; i < n - 1; i++)
  {
    cin >> u >> v;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  vis[r] = true;
  D[r] = subTree(r);

  while (q--)
  {
    cin >> u;
    cout << D[u] << "\n";
  }
  return 0;
}

int subTree(int root)
{
  int cnt = 1;
  for (int v : edge[root])
  {
    if (vis[v]) continue;
    vis[v] = true;
    D[v] = subTree(v);
    cnt += D[v];
  }
  return cnt;
}