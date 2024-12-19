#include <iostream>
#include <queue>

#define INF 2147483647

using namespace std;

int dis[101][101] = {};

int n;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <=n; j++)
			if (i != j) dis[i][j] = INF;
	}

	int input;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> input;
			if (input == 1)
				dis[i][j] = 1;
		}
	}

	for (int k = 1; k <= n; k++)
	{
		for (int s = 1; s <= n; s++)
		{
			for (int t = 1; t <= n; t++)
			{
				if (dis[s][k] != INF && dis[k][t] != INF && (dis[s][t] > dis[s][k] + dis[k][t] || dis[s][t] == 0))
					dis[s][t] = dis[s][k] + dis[k][t];
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dis[i][j] != INF && dis[i][j] > 0)
				cout << "1 ";
			else
				cout << "0 ";
		}
		cout << "\n";
	}

	return 0;
}