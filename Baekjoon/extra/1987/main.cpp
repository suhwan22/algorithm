/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-1987
 * Created     : 2025-03-20 19:17:00
 * Updated     : 2025-03-20 20:22:22
 */

#include <iostream>
#include <queue>

using namespace std;

int n, m, ans;
char board[20][20];
bool visited[26];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

void dfs(int x, int y, int cnt);

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < m; j++)
			board[i][j] = input[j];
	}
	visited[board[0][0] - 'A'] = true;
	dfs(0, 0, 1);
	cout << ans;

	return 0;
}

void dfs(int x, int y, int cnt)
{
	if (cnt > ans)
		ans = cnt;
	int nx, ny;
	for (int i = 0; i < 4; i++)
	{
		nx = x + dx[i];
		ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (visited[board[nx][ny] - 'A']) continue;
		visited[board[nx][ny] - 'A'] = true;
		dfs(nx, ny, cnt + 1);
		visited[board[nx][ny] - 'A'] = false;
	}
}
