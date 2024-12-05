#include <iostream>
#include <queue>

using namespace std;

bool adj[501][501] = {};

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	int u, v;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		adj[u][v] = true;
		adj[v][u] = true;
	}
	bool visit[501] = {};
	visit[1] = true;
	queue<int> q;
	q.push(1);
	q.push(-1);
	int cnt = 0, depth = 1, cur;
	while (!q.empty())
	{
		cur = q.front();
		q.pop();
		if (cur < 0)
		{
			depth++;
			if (depth > 2)
				break;
			q.push(-1);
			continue;
		}
		for (int i = 1; i <= n; i++)
		{
			if (visit[i]) continue;
			if (adj[cur][i] == false) continue;
			visit[i] = true;
			cnt++;
			q.push(i);
		}
	}
	cout << cnt;

	return 0;
}