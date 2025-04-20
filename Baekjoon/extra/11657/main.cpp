/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-11657
 * Created     : 2025-04-20 21:05:03
 * Updated     : 2025-04-20 21:30:44
 */

#include <iostream>
#include <vector>
#include <tuple>

#define INF 1000000000

using namespace std;

int n, m;
vector<tuple<int, int, int>> edge;
vector<long long> dis(501, INF);

bool bellmanford(int start)
{
	dis[start] = 0;
	int from, to, w;
	bool flag;
	for (int i = 0; i < n; i++)
	{
		flag = true;
		for (int j = 0; j < m; j++)
		{
			tie(from, to, w) = edge[j];
			if (dis[from] != INF && dis[to] > dis[from] + w)
			{
				dis[to] = dis[from] + w;
				flag = false;
			}
		}
		if (flag)
			break;
	}
	return flag;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	int u, v, w;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v >> w;
		edge.push_back({u, v, w});
	}
	if (!bellmanford(1))
		cout << -1;
	else
	{
		for (int i = 2; i <= n; i++)
			cout << (dis[i] == INF ? -1 : dis[i]) << "\n";
	}

	return 0;
}
