#include <iostream>
#include <deque>

#define INF 2147483647

using namespace std;

int n, m;
int dis[101][101] = {};
int nxt[101][101] = {};

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
		if (dis[u][v] > w)
		{
			dis[u][v] = w;
			nxt[u][v] = v;
		}
	}
	
	for (int k = 1; k <= n; k++)
	{
		for (int s = 1; s <= n; s++)
		{
			for (int t = 1; t <= n; t++)
			{
				if (dis[s][k] != INF && dis[k][t] != INF && dis[s][t] > dis[s][k] + dis[k][t])
				{
					dis[s][t] = dis[s][k] + dis[k][t];
					nxt[s][t] = nxt[s][k];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			if (dis[i][j] == INF)
				cout << "0 ";
			else
				cout << dis[i][j] << " ";
		cout << "\n";
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dis[i][j] == 0 || dis[i][j] == INF)
			{
				cout << "0\n";
				continue;
			}
			deque<int> path;
			int st = i;
			while (st != j)
			{
				path.push_back(st);
				st = nxt[st][j];
			}
			path.push_back(j);
			cout << path.size() << ' ';
			for (auto x : path)
				cout << x << ' ';
			cout << '\n';
		}
	}

	return 0;
}