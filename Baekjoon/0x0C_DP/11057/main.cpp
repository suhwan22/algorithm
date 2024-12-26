#include <iostream>

using namespace std;

int n;
int D[1001][11] = {};

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < 10; i++)
		D[1][i] = 10 - i;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 9; j >= 0; j--)
			D[i][j] = (D[i][j+1] + D[i-1][j]) % 10007;
	}
	cout << D[n][0];

	return 0;
}