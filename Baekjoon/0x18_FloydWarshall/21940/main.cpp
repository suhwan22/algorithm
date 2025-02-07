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
	// �÷��̵带 ����ϱ� ���ؼ� �̸� INF�� �ʱ�ȭ
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			dis[i][j] = i != j ? INF : 0;
	}

	// ���� ������ �Է¹޴´�.
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

	// ģ�� ���� �Է¹޴´�.
	cin >> k;
	int c;
	for (int i = 0; i < k; i++)
	{
		cin >> c;
		friends.push_back(c);
	}

	// ģ������ i���÷� �պ����� �� �ʿ��� �Ÿ� �߿��� �ִ��� ���� ���� ���� ã�´�.
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
