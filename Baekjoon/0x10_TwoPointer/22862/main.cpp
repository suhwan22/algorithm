#include <iostream>

using namespace std;

int n, k;
int arr[1000000] = {};

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int st = 0, en = 0, cnt = 0;
	int max = 0;
	while (en < n)
	{
		if (arr[en] % 2 == 0)
			en++;
		else
		{
			cnt++;
			while (cnt > k && st < en)
			{
				if (arr[st++] % 2 == 1)
					cnt--;
			}
			en++;
		}
		if (en - st - cnt > max)
			max = en - st - cnt;
	}
	cout << max;

	return 0;
}
