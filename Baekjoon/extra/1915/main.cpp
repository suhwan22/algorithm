/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-1915
 * Created     : 2025-04-01 22:44:34
 * Updated     : 2025-04-01 23:06:48
 */

#include <iostream>

using namespace std;

int n, m;
int board[1001][1001];

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < m; j++)
			board[i][j+1] = input[j] - '0';
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (board[i][j] == 0) continue;
			board[i][j] = min(min(board[i-1][j], board[i-1][j-1]), board[i][j-1]) + 1;
			if (ans < board[i][j])
				ans = board[i][j];
		}
	}
	cout << ans * ans;

	return 0;
}
