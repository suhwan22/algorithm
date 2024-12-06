#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
vector<int> adj[1001] = {};
int indegree[1001] = {};
bool visit[1001] = {};
queue<int> q;

bool isCycle();
bool dfs(vector<int> re, int cur);

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	int k;
	int u, v;
	for (int i = 0; i < m; i++)
	{
		cin >> k;
		cin >> u;
		for (int j = 1; j < k; j++)
		{
			cin >> v;
			if (find(adj[u].begin(), adj[u].end(), v) == adj[u].end())
			{
				adj[u].push_back(v);
				indegree[v]++;
			}
			u = v;
		}
	}
	if (isCycle())
		cout << "0";
	else
	{
		queue<int> q;
		int cur;
		for (int i = 1; i <= n; i++)
		{
			if (indegree[i] == 0)
				q.push(i);
		}
		while (!q.empty())
		{
			cur = q.front();
			q.pop();
			cout << cur << "\n";
			for (int v : adj[cur])
			{
				indegree[v]--;
				if (indegree[v] == 0)
					q.push(v);
			}
		}
	}

	return 0;
}

bool isCycle()
{
	for (int i = 1; i <= n; i++)
	{
		if (::visit[i]) continue;
		for (int nxt : adj[i])
		{
			vector<int> re;
			re.push_back(i);
			if (!dfs(re, nxt))
				return true;
		}
	}
	return false;
}

bool dfs(vector<int> re, int cur)
{
	if (find(re.begin(), re.end(), cur) != re.end())
		return false;
	re.push_back(cur);
	if (::visit[cur])
		return true;
	::visit[cur] = true;
	for (int v : adj[cur])
	{
		if (!dfs(re, v))
			return false;
	}
	return true;
}