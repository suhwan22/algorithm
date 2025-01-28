#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int n, m, c;
pair<int, pair<int, int>> items[10000] = {};
int stuck[2001] = {};

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> c >> m;
	for (int i = 0; i < m; i++)
		cin >> items[i].second.first >> items[i].first >> items[i].second.second;
	sort(items, items + m);
	for (int i = 1; i <= n; i++)
		stuck[i] = c;
	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		int min = 2147483647;
		for (int j = items[i].second.first; j < items[i].first; j++)
			if (min > stuck[j])
				min = stuck[j];
		int carry = min >= items[i].second.second ? items[i].second.second : min;
		for (int j = items[i].second.first; j < items[i].first; j++)
			stuck[j] -= carry;
		ans += carry;
	}
	cout << ans;

	return 0;
}
