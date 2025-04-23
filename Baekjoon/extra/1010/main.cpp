/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj
 * Created     : 2025-04-23 22:01:29
 * Updated     : 2025-04-23 22:08:15
 */

#include <iostream>

using namespace std;

int tc, n, m;
long long dp[30][30];

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	for (int i = 1; i < 30; i++)
	{
		dp[i][1] = i;
		dp[i][i] = 1;
		for (int j = 2; j < i && i != 1; j++)
			dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
	}
	cin >> tc;
	while (tc--)
	{
		cin >> n >> m;
		cout << dp[m][n] << "\n";
	}

	return 0;
}