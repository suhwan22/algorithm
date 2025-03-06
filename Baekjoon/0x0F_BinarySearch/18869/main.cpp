/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-18869
 * Created     : 2025-03-06 16:44:28
 * Updated     : 2025-03-06 17:40:45
 */

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

pair<int, int> arr[10000];
int order[100][10000];
int n, m;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[j].first;
			arr[j].second = j;
		}
		sort(arr, arr + n);
		int seq = 0;
		for (int j = 0; j < n; j++)
		{
			order[i][arr[j].second] = seq;
			if (j != n - 1 && arr[j].first < arr[j + 1].first)
				seq++;
		}
	}
	
	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			bool flag = true;
			for (int idx = 0; idx < n; idx++)
			{
				if (order[i][idx] != order[j][idx])
				{
					flag = false;
					break;
				}
			}
			if (flag)
				ans++;
		}
	}
	cout << ans;

	return 0;
}