/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-1774
 * Created     : 2025-02-11 18:36:17
 * Updated     : 2025-02-11 21:39:07
 */

#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int n, m;
double ans = 0;
vector<pair<int, int>> pos;
vector<pair<double, int>> adj[1001];
bool visited[1001];
priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	int x, y;
	pos.push_back({-1, -1});
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		pos.push_back({x, y});
	}
	int u, v;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		adj[u].push_back({0, v});
		adj[v].push_back({0, u});
	}

	pair<double, int> cur;
	pq.push({0, u});
	while (!pq.empty())
	{
		cur = pq.top();
		pq.pop();
		if (visited[cur.second]) continue;
		visited[cur.second] = true;
		ans += cur.first;
		for (auto i : adj[cur.second])
			pq.push(i);
		for (int i = 1; i <= n; i++)
		{
			if (visited[i]) continue;
			double dis = sqrt(pow(pos[cur.second].first - pos[i].first, 2) + pow(pos[cur.second].second - pos[i].second, 2));
			pq.push({dis, i});
		}
	}
	cout << fixed;
	std::cout.precision(2);
	cout << ans;

	return 0;
}
