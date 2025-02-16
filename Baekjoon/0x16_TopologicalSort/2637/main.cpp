/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj
 * Created     : 2025-02-16 21:32:07
 * Updated     : 2025-02-16 22:13:29
 */

#include <iostream>
#include <queue>

using namespace std;

int n, m;
int cnt[101];
int indegree[101];
int outdegree[101];
vector<pair<int, int>> adj[101];
queue<int> q;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	int u, v, w;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v >> w;
		indegree[v]++;
		outdegree[u]++;
		adj[u].push_back({v, w});
	}
	cnt[n] = 1;
	q.push(n);
	int cur;
	while (!q.empty())
	{
		cur = q.front();
		q.pop();
		for (auto p : adj[cur])
		{
			cnt[p.first] += cnt[cur] * p.second;
			if (--indegree[p.first] == 0)
				q.push(p.first);
		}
	}
	for (int i = 1; i <= n; i++)
		if (outdegree[i] == 0)
			cout << i << " " << cnt[i] << "\n";

	return 0;
}