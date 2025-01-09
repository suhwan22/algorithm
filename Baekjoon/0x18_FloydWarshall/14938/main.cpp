#include <iostream>
#include <queue>

#define INF 1000000000

using namespace std;

int n, m, r;

int item[101] = {};
int dis[101][101] = {};
int max = 0;

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	// 변수 초기화
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++)
		cin >> item[i];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			if (i != j) dis[i][j] = INF;
	}
	int u, v, w;
	for (int i = 0; i < r; i++)
	{
		cin >> u >> v >> w;
		dis[u][v] = w;
		dis[v][u] = w;
	}

	// 플로이드-워셜
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

	// 모든 경우의 수에 대해서 먹을 수 있는 item의 수를 bfs로 구한다.
	for (int i = 1; i <= n; i++)
	{
		bool visit[101] = {};
		queue<pair<int, int>> q;
		pair<int, int> cur;
		visit[i] = true;
		q.push({i, 0});
		int cnt = item[i];
		while (!q.empty())
		{
			cur = q.front();
			q.pop();
			for (int j = 1; j <= n; j++)
			{
				if (i == j || dis[i][j] == INF) continue;
				if (visit[j] || cur.second + dis[i][j] > m) continue;
				visit[j] = true;
				cnt += item[j];
				q.push({j, cur.second + dis[i][j]});
			}
		}
		if (::max < cnt)
			::max = cnt;
	}
	cout << ::max;

	return 0;
}
