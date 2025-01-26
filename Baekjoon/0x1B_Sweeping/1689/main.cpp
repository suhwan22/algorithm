#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int n;
pair<int, int> arr[2000000] = {};

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	int st, en;
	for (int i = 0; i < 2 * n; i+=2)
	{
		cin >> st >> en;
		arr[i] = {st, 1};
		arr[i+1] = {en, -1};
	}
	sort(arr, arr + 2 * n);
	int cnt = 0;
	int max = 0;
	for (int i = 0; i < 2 * n; i++)
	{
		cnt += arr[i].second;
		if (max < cnt)
			max = cnt;
	}
	cout << max;

	return 0;
}
