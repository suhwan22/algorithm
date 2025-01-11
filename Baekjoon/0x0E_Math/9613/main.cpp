#include <iostream>

using namespace std;

int t, n;
int arr[100] = {};

int gcd(int a, int b);
long long ans = 0;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> t;
	while (t--)
	{
		cin >> n;
		ans = 0;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
				ans += gcd(arr[i], arr[j]);
		}
		cout << ans << "\n";
	}

	return 0;
}

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}