/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-1781
 * Created     : 2025-02-12 16:27:06
 * Updated     : 2025-02-13 01:33:25
 */

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n;
long long ans;
pair<int, int> arr[200001];
priority_queue<int> pq;

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + n, greater<pair<int, int>>());

	int cur;
	for (int date = arr[0].first, idx = 0; date > 0; date--)
	{
		for (; idx < n && arr[idx].first == date; idx++)
			pq.push(arr[idx].second);
		if (pq.empty()) continue;
		cur = pq.top();
		pq.pop();
		ans += cur;
	}
	cout << ans;

	return 0;
}
