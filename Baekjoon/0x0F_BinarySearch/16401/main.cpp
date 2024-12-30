#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int snack[1000000] = {};

bool isValid(int len);

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> m >> n;
	for (int i = 0; i < n; i++)
		cin >> snack[i];
	sort(snack, snack + n);
	int st = 0, en = snack[n-1], mid;
	while (st < en)
	{
		mid = (st + en + 1) / 2;	
		if (isValid(mid))
			st = mid;
		else
			en = mid - 1;
	}
	cout << st;

	return 0;
}

bool isValid(int len)
{
	int temp, i, idx;
	temp = snack[n - 1];
	for (i = 0, idx = n - 1; i < m && idx >= 0; i++)
	{
		if (temp < len)
			return false;
		if (temp - len >= len)
			temp -= len;
		else if (idx > 0)
			temp = snack[--idx];
		else
			break;
	}
	if (i < m - 1)
		return false;
	return true;
}