/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://eventually-useful.tistory.com/15
 * Created     : 2025-03-19 23:04:07
 * Updated     : 2025-03-19 23:38:01
 */

#include <iostream>

using namespace std;

int n, k;
int dp[10001];
int coin[101];

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;

	for (int i = 1; i <= k; i++)
		dp[i] = -1;

	int v;
	for (int i = 0; i < n; i++)
		cin >> coin[i];

	for (int a : coin)
	{
		for (int i = a; i <= k; i++)
		{
			if (dp[i - a] == -1) continue;
			if (dp[i] == -1 || dp[i] > dp[i-a] + 1)
				dp[i] = dp[i-a] + 1;
		}
	}

	cout << dp[k];

	return 0;
}
