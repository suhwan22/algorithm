#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> adj[32001] = {};
int indegree[32001] = {};
queue<int> q;

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
		indegree[v]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0)
			q.push(i);
	}
	int cur;
	while (!q.empty())
	{
		cur = q.front();
		q.pop();
		cout << cur << " ";
		for (int v : adj[cur])
		{
			indegree[v]--;
			if (indegree[v] == 0)
				q.push(v);
		}
	}

	return 0;
}
