/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-1389
 * Created     : 2025-02-13 22:07:07
 * Updated     : 2025-02-13 22:13:33
 */

#include <iostream>

#define INF 1000000000

using namespace std;

int n, m;
int dis[101][101];

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	int u, v;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dis[i][j] = i != j ? INF : 0;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		dis[u][v] = 1;
		dis[v][u] = 1;
	}
	for (int k = 1; k <= n; k++)
	{
		for (int s = 1; s <= n; s++)
		{
			for (int t = 1; t <= n; t++)
				if (dis[s][t] > dis[s][k] + dis[k][t])
					dis[s][t] = dis[s][k] + dis[k][t];
		}
	}
	int min = INF;
	int num = 0;
	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= n; j++)
			cnt += dis[i][j];
		if (min > cnt)
		{
			min = cnt;
			num = i;
		}
	}
	cout << num;

	return 0;
}
