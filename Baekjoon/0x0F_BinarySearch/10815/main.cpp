#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr;

bool binarySearch(int input);

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n;
	int input;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		arr.push_back(input);
	}
	sort(arr.begin(), arr.end());
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> input;
		cout << binarySearch(input) << " ";
	}

	return 0;
}

bool binarySearch(int input)
{
		int st = 0, en = arr.size() - 1;
		while (st <= en)
		{
			int mid = (st + en) / 2;
			if (arr[mid] > input)
				en = mid - 1;
			else if (arr[mid] < input)
				st = mid + 1;
			else if (arr[mid] == input)
				return true;
		}
		return false;
}