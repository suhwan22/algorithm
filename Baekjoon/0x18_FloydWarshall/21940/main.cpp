/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-21940
 * Created     : 2025-02-07 17:35:41
 * Updated     : 2025-02-07 19:08:17
 */

#include <iostream>
#include <vector>

#define INF 1000000000

using namespace std;

int n, m, k;
int dis[201][201];
vector<int> friends;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	// 플로이드를 사용하기 위해서 미리 INF로 초기화
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			dis[i][j] = i != j ? INF : 0;
	}

	// 간선 정보를 입력받는다.
	int u, v, w;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v >> w;
		dis[u][v] = w < dis[u][v] ? w : dis[u][v];
	}

	for (int mid = 1; mid <= n; mid++)
	{
		for (int s = 1; s <= n; s++)
		{
			for (int t = 1; t <= n; t++)
			{
				if (dis[s][t] > dis[s][mid] + dis[mid][t])
					dis[s][t] = dis[s][mid] + dis[mid][t];
			}
		}
	}

	// 친구 정보 입력받는다.
	cin >> k;
	int c;
	for (int i = 0; i < k; i++)
	{
		cin >> c;
		friends.push_back(c);
	}

	// 친구들이 i도시로 왕복했을 때 필요한 거리 중에서 최댓값이 가장 작은 것을 찾는다.
	int maxdis[201] = {};
	int min = INF;
	for (int i = 1; i <= n; i++)
	{
		int max = 0;
		for (int f : friends)
		{
			if (max < dis[f][i] + dis[i][f])
				max = dis[f][i] + dis[i][f];
		}
		maxdis[i] = max;
		if (min > max)
			min = max;
	}

	for (int i = 1; i <= n; i++)
	{
		if (maxdis[i] == min)
			cout << i << " ";
	}

	return 0;
}
