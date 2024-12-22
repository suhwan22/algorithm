#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[500000] = {};
int b[500000] = {};

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	sort(a, a + n);
	sort(b, b + m);

	vector<int> arr;
	for (int i = 0; i < n; i++)
	{
		int target = a[i];
		int st = 0, en = m - 1, mid;
		bool flag = true;
		while (st <= en)
		{
			mid = (st + en + 1) / 2;
			if (b[mid] == target)
			{
				flag = false;
				break;
			}
			else if (b[mid] < target)
				st = mid + 1;
			else if (b[mid] > target)
				en = mid - 1;
		}
		if (flag)
			arr.push_back(target);
	}
	cout << arr.size() << "\n";
	for (int num : arr)
		cout << num << " ";

	return 0;
}