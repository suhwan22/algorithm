#include <iostream>

using namespace std;

int t, n;
int board[2][100000] = {};
int D[3][100000] = {};

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < n; j++)
				cin >> board[i][j];
		}
		D[0][0] = board[0][0];
		D[1][0] = board[1][0];
		D[2][0] = 0;
		for (int i = 1; i < n; i++)
		{
			D[0][i] = board[0][i] + max(D[1][i-1], D[2][i-1]);
			D[1][i] = board[1][i] + max(D[0][i-1], D[2][i-1]);
			D[2][i] = max(D[0][i-1], D[1][i-1]);
		}
		cout << max(D[0][n-1], D[1][n-1]) << "\n";
	}

	return 0;
}