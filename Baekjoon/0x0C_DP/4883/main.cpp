#include <iostream>

#define INF 9999999

using namespace std;

int board[100000][3] = {};

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n, cnt = 1;
	while (1)
	{
		cin >> n;
		if (n == 0)
			break;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 3; j++)
				cin >> board[i][j];
		}
		board[0][0] = INF;
		board[0][2] += board[0][1];
		for (int i = 1; i < n; i++)
		{
			board[i][0] += min(board[i-1][0], board[i-1][1]);
			board[i][1] += min(min(board[i-1][0], board[i-1][1]), min(board[i-1][2], board[i][0]));
			board[i][2] += min(min(board[i-1][1], board[i-1][2]), board[i][1]);
		}
		cout << cnt++ << ". " << board[n-1][1] << "\n";
	}

	return 0;
}
