/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj
 * Created     : 2025-05-06 00:50:14
 * Updated     : 2025-05-06 01:34:11
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int n;
int arr[2001];
unordered_map<int, vector<pair<int, int>>> sum;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
			sum[arr[i] + arr[j]].push_back({i, j});
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (auto p : sum[arr[i]])
		{
			if (p.first != i && p.second != i)
			{
				cnt++;
				break;
			}
		}
	}
	cout << cnt;

	return 0;
}
