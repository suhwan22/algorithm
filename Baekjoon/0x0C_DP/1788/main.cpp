#include <iostream>

using namespace std;

int n;
long long D[2000001] = {};

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	D[1000000] = 0;
	D[1000001] = 1;
	n += 1000000;
	if (n > 1000000)
	{
		for (int i = 1000002; i <= n; i++)
			D[i] = (D[i - 1] + D[i - 2]) % 1000000000;
	}
	else
	{
		for (int i = 999999; i >= n; i--)
			D[i] = (D[i + 2] - D[i + 1]) % 1000000000;
	}
	if (D[n] < 0)
		cout << "-1\n" << -D[n];
	else if (D[n] > 0)
		cout << "1\n" << D[n];
	else
		cout << "0\n0";

	return 0;
}
