/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-1699
 * Created     : 2025-03-05 22:09:12
 * Updated     : 2025-03-05 22:47:34
 */

#include <iostream>

using namespace std;

int n;
int dp[100001] = {0, 1, 2, };

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[1] + dp[i - 1];
		for (int j = 1; j * j <= i; j++)
		{
			dp[i] = min(dp[j * j] + dp[i - j * j], dp[i]);
			if (j * j == i)
				dp[i] = 1;
		}
	}
	cout << dp[n];

	return 0;
}
