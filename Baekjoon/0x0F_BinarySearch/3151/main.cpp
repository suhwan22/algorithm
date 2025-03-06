/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-3151
 * Created     : 2025-03-06 18:05:51
 * Updated     : 2025-03-06 19:27:45
 */

#include <iostream>
#include <algorithm>

using namespace std;

int arr[10000];
int n;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);

	long long ans = 0;
	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			int sum = arr[i] + arr[j];
			int *it1 = lower_bound(arr + j + 1, arr + n, -sum);
			int *it2 = upper_bound(arr + j + 1, arr + n, -sum);
			ans += it2 - it1;
		}
	}
	cout << ans;

	return 0;
}
