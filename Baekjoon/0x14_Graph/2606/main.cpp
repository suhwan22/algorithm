#include <iostream>
#include <queue>

using namespace std;

vector<int> adj[101] = {};

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	int u, v;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bool visit[101] = {};
	visit[1] = true;
	queue<int> q;
	q.push(1);
	int cur;
	int cnt = 0;
	while (!q.empty())
	{
		cur = q.front();
		q.pop();
		for (int u : adj[cur])
		{
			if (visit[u]) continue;
			visit[u] = true;
			q.push(u);
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}