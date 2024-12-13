#include <iostream>
#include <algorithm>

using namespace std;

int board[10][10] = {};
int n, k;
int seq[3][20] = {};
int idx[3] = {};

int playGame(int a, int b);

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> board[i][j];
	}
	for (int i = 1; i < 3; i++)
	{
		for (int j = 0; j < 20; j++)
			cin >> seq[i][j];
	}
	for (int i = 0; i < n; i++)
		seq[0][i] = i + 1;
	do
	{
		int a = 0, b = 1, nx;
		int win[3] = {};
		idx[0] = 0; idx[1] = 0; idx[2] = 0;
		while (1)
		{
			nx = playGame(a, b);
			win[nx]++;
			if (win[nx] >= k)
				break;
			if (idx[0] >= n)
				break;
			b = 3 - (a + b);
			a = nx;
		}
		if (win[0] >= k)
		{
			cout << 1;
			return 0;
		}
	} while (next_permutation(seq[0], seq[0] + n));
	cout << 0;

	return 0;
}

int playGame(int player1, int player2)
{
	int a = seq[player1][idx[player1]++];
	int b = seq[player2][idx[player2]++];
	if (board[a][b] == 2)
		return player1;
	if (board[b][a] == 2)
		return player2;
	return player1 > player2 ? player1 : player2;
}