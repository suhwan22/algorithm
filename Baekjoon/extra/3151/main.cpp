/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-3151
 * Created     : 2025-03-06 19:26:53
 * Updated     : 2025-03-06 20:53:29
 */

#include <iostream>
#include <algorithm>

using namespace std;

int n;
int cnt[20001];
int arr[10000];

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	long long ans = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int sum = -(arr[i] + arr[j]) + 10000;
			if (sum < 0 || sum > 20000) continue;
			ans += cnt[sum];
		}
		cnt[arr[i] + 10000]++;
	}
	cout << ans;

	return 0;
}
