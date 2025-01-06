#include <iostream>
#include <vector>

#define INF 1000000000

using namespace std;

int n;
int dis[51][51] = {};

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	int u, v;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			dis[i][j] = INF;
		}
	}
	while (1)
	{
		cin >> u >> v;
		if (u == -1 || v == -1)
			break;
		dis[u][v] = 1;
		dis[v][u] = 1;
	}
	for (int k = 1; k <= n; k++)
	{
		for (int s = 1; s <= n; s++)
		{
			for (int t = 1; t <= n; t++)
			{
				if (dis[s][t] > dis[s][k] + dis[k][t])
					dis[s][t] = dis[s][k] + dis[k][t];
			}
		}
	}
	int score[51] = {};
	int min = 50;
	for (int i = 1; i <= n; i++)
	{
		score[i] = 1;
		for (int j = 1; j <= n; j++)
		{
			if (dis[i][j] > score[i])
				score[i] = dis[i][j];
		}
		if (score[i] < min)
			min = score[i];
	}
	vector<int> seq;
	for (int i = 1; i <= n; i++)
	{
		if (score[i] == min)
			seq.push_back(i);
	}
	cout << min << " " << seq.size() << "\n";
	for (int e : seq)
		cout << e << " ";

	return 0;
}
