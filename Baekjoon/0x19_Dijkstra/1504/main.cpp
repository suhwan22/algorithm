/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-1504
 * Created     : 2025-02-07 19:17:32
 * Updated     : 2025-02-07 21:53:49
 */

#include <iostream>
#include <queue>

#define INF 100000000

using namespace std;

int n, m, v1, v2;
vector<pair<int, int>> adj[801];
int dis[801];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijkstra(int st);

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	int u, v, w;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v >> w;
		adj[u].push_back({w, v});
		adj[v].push_back({w, u});
	}
	cin >> v1 >> v2;
	int st_v1, st_v2, v1_en, v2_en, v1_v2;
	dijkstra(1);
	st_v1 = dis[v1];
	st_v2 = dis[v2];
	dijkstra(n);
	v1_en = dis[v1];
	v2_en = dis[v2];
	dijkstra(v1);
	v1_v2 = dis[v2];

	int ans = min((st_v1 + v1_v2 + v2_en), (st_v2 + v1_v2 + v1_en));
	cout << ( ans >= 100000000 ? -1 : ans);

	return 0;
}

void dijkstra(int st)
{
	for (int i = 1; i <= n; i++)
		dis[i] = INF;
	dis[st] = 0;
	pq.push({0, st});
	pair<int, int> cur;
	while (!pq.empty())
	{
		cur = pq.top();
		pq.pop();
		if (cur.first > dis[cur.second])
			continue;
		for (int i = 0; i < (int)adj[cur.second].size(); i++)
		{
			if (dis[cur.second] + adj[cur.second][i].first < dis[adj[cur.second][i].second])
			{
				dis[adj[cur.second][i].second] = dis[cur.second] + adj[cur.second][i].first;
				pq.push({dis[adj[cur.second][i].second], adj[cur.second][i].second});
			}
		}
	}
}