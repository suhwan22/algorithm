#include <iostream>
#include <queue>

using namespace std;

int n, m;
vector<pair<int, int>> adj[1001] = {};
priority_queue<pair<int, int>> pq;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	int u, v, w;
	for (int i = 0; i <= m; i++)
	{
		cin >> u >> v >> w;
		adj[u].push_back({w, v});
		adj[v].push_back({w, u});
	}
	bool visited[1001] = {};
	pq.push({1, 0});
	pair<int, int> cur;
	int min = 0;
	while (!pq.empty())
	{
		cur = pq.top();
		pq.pop();
		if (visited[cur.second])
			continue;
		visited[cur.second] = true;
		if (cur.first == 0)
			min++;
		for (auto p : adj[cur.second])
		{
			if (visited[p.second]) continue;
			pq.push(p);
		}
	}

	bool visited2[1001] = {};
	pq2.push({1, 0});
	int max = 0;
	while (!pq2.empty())
	{
		cur = pq2.top();
		pq2.pop();
		if (visited2[cur.second])
			continue;
		visited2[cur.second] = true;
		if (cur.first == 0)
			max++;
		for (auto p : adj[cur.second])
		{
			if (visited2[p.second]) continue;
			pq2.push(p);
		}
	}
	cout << max  * max - min * min;

	return 0;
}
