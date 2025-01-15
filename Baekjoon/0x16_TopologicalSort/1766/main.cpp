#include <iostream>
#include <queue>

using namespace std;

int n, m;
vector<int> adj[32001] = {};
int indegree[32001] = {};
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	int u, v;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		indegree[v]++;
		adj[u].push_back(v);
	}
	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0)
			pq.push(i);
	}
	int cur;
	while (!pq.empty())
	{
		cur = pq.top();
		pq.pop();
		cout << cur << " ";
		for (int i : adj[cur])
		{
			if (--indegree[i] == 0)
				pq.push(i);
		}
	}

	return 0;
}
