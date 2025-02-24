/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-10942
 * Created     : 2025-02-24 18:42:22
 * Updated     : 2025-02-24 19:09:31
 */

#include <iostream>

using namespace std;

int n, m;
bool dp[2001][2001];
int arr[2001];

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	for (int i = 1; i <= n; i++)
	{
		dp[i][i] = true;
		for (int j = i - 1; j >= 1; j--)
		{
			if (arr[i] != arr[j]) continue;
			if (i - j == 1)
				dp[j][i] = true;
			else
				dp[j][i] = dp[j+1][i-1];
		}
	}
	cin >> m;
	int s, e;
	while (m--)
	{
		cin >> s >> e;
		cout << dp[s][e] << "\n";
	}

	return 0;
}
