#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int n;
pair<int, int> arr[1000000] = {};

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + n);
	int st = arr[0].first, en = arr[0].second;
	int ans = 0;
	for (int i = 1; i < n; i++)
	{
		if (arr[i].first > en)
		{
			ans += en - st;
			st = arr[i].first;
		}
		if (en < arr[i].second)
			en = arr[i].second;
	}
	ans += en - st;
	cout << ans;

	return 0;
}
