/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-1261
 * Created     : 2025-03-07 21:46:56
 * Updated     : 2025-03-07 22:20:04
 */

#include <iostream>
#include <queue>
#include <tuple>

#define INF 1000000000

using namespace std;

int n, m;
int board[100][100];
int dis[100][100];
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> m >> n;
	string input;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		for (int j = 0; j < m; j++)
		{
			board[i][j] = input[j] - '0';
			dis[i][j] = INF;
		}
	}

	dis[0][0] = 0;
	pq.push({0, 0, 0});
	int w, x, y;
	int nw, nx, ny;
	while (!pq.empty())
	{
		tie(w, x ,y) = pq.top();
		pq.pop();
		if (w > dis[x][y]) continue;
		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			nw = w + board[nx][ny];
			if (dis[nx][ny] > nw)
			{
				dis[nx][ny] = nw;
				pq.push({nw, nx, ny});
			}
		}
	}
	cout << dis[n-1][m-1];

	return 0;
}
