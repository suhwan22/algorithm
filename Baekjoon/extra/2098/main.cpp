/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-2098
 * Created     : 2025-03-31 18:13:18
 * Updated     : 2025-03-31 18:13:18
 */

#include <iostream>
#include <cstring>
#include <tuple>
#include <queue>

#define INF 1000000000

using namespace std;

int n;
int ans = INF;
int adj[16][16];
int dp[65536][16];

queue<tuple<int, int, int>> q;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> adj[i][j];
			if (adj[i][j] == 0)
				adj[i][j] = INF;
		}
	}
	int visited, cur, w;
	q.push({0, 0, 0});
	while (!q.empty())
	{
		tie(w, visited, cur) = q.front();
		q.pop();
		if (dp[visited][cur] != 0 && dp[visited][cur] < w) continue;
		for (int nxt = 0; nxt < n; nxt++)
		{
			if (cur == nxt || adj[cur][nxt] == INF) continue;
			if (visited & (1 << nxt)) continue;
			int bit = visited | (1 << nxt);
			if (dp[bit][nxt] != 0 && dp[bit][nxt] <= w + adj[cur][nxt]) continue;
			dp[bit][nxt] = w + adj[cur][nxt];
			q.push({w + adj[cur][nxt], bit, nxt});
		}
	}
	cout << dp[(1 << n) - 1][0];

	return 0;
}
