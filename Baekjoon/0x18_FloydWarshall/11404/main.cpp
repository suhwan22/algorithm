#include <iostream>

#define INF 2147483647

using namespace std;

int n, m;
int dis[101][101] = {};

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			if (i != j) dis[i][j] = INF;
	}
	int u, v, w;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v >> w;
		dis[u][v] = min(dis[u][v], w);
	}

	for (int k = 1; k <= n; k++)
	{
		for (int s = 1; s <= n; s++)
		{
			for (int t = 1; t <= n; t++)
				if (dis[s][k] != INF && dis[k][t] != INF && dis[s][t] > dis[s][k] + dis[k][t])
					dis[s][t] = dis[s][k] + dis[k][t];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << (dis[i][j] != INF ? dis[i][j] : 0)<< " ";
		cout << "\n";
	}

	return 0;
}