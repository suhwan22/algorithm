#include <iostream>
#include <queue>

using namespace std;

int n, m;
vector<pair<int, int>> adj[1001] = {};
int dis[1001][1001] = {};

void calDis(int root, int parent, int cur, int depth);

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	int u, v, w;
	for (int i = 1; i < n; i++)
	{
		cin >> u >> v >> w;
		adj[u].push_back({w, v});
		adj[v].push_back({w, u});
	}
	for (int i = 1; i < n; i++)
		calDis(i, -1, i, 0);
	while (m--)
	{
		cin >> u >> v;
		cout << dis[u][v] << "\n";
	}

	return 0;
}

void calDis(int root, int parent, int cur, int depth)
{
	for (auto v : adj[cur])
	{
		if (parent == v.second)
			continue;
		dis[root][v.second] = depth + v.first;
		dis[v.second][root] = depth + v.first;
		calDis(root, cur, v.second, depth + v.first);
	}
}