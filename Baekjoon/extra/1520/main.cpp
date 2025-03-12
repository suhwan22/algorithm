/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-1520
 * Created     : 2025-03-13 00:31:32
 * Updated     : 2025-03-13 01:50:27
 */

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n, m;
int board[500][500];
int dp[500][500];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
priority_queue<tuple<int, int, int>> pq;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	}
	dp[0][0] = 1;
	pq.push({board[0][0], 0, 0});
	int w, x, y;
	int nx, ny;
	while (!pq.empty())
	{
		tie(w, x, y) = pq.top();
		pq.pop();
		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (board[nx][ny] >= board[x][y]) continue;
			if (dp[nx][ny] == 0)
				pq.push({board[nx][ny], nx, ny});
			dp[nx][ny] += dp[x][y];
		}
	}
	cout << dp[n-1][m-1];

	return 0;
}
