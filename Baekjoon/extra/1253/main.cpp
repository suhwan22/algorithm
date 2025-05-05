/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj
 * Created     : 2025-05-06 01:34:27
 * Updated     : 2025-05-06 01:40:00
 */

#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[2001];

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		int st = 0, en = n - 1, target = arr[i];
		while (st < en)
		{
			int sum = arr[st] + arr[en];
			if (sum == target)
			{
				if (st != i && en != i)
				{
					cnt++;
					break;
				}
				if (st == i)
					st++;
				else if (en == i)
					en--;
			}
			else if (sum < target)
				st++;
			else if (sum > target)
				en--;
		}
	}
	cout << cnt;

	return 0;
}
