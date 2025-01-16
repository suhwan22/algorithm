#include <iostream>

using namespace std;

int n, k;
int C[1001][1001] = {};

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		C[i][0] = 1;
		C[i][i] = 1;
		for (int j = 1; j < i; j++)
			C[i][j] = (C[i-1][j-1] + C[i-1][j]) % 10007;
	}
	cout << C[n][k];

	return 0;
}