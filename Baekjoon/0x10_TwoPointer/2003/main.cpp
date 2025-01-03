#include <iostream>

using namespace std;

int n, m;
int arr[10001] = {};

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int st = 0, en = 0;
	long long sum = 0;
	int cnt = 0;
	while (st <= en && en <= n)
	{
		if (sum > m)
			sum -= arr[st++];
		else if (sum <= m)
		{
			if (sum == m)
				cnt++;
			sum += arr[en++];
		}
	}
	cout << cnt;

	return 0;
}
