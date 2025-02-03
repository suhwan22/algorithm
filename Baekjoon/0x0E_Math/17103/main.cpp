#include <iostream>

using namespace std;

bool prime[1000001] = {1, 1, };

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	for (int i = 2; i <= 1000; i++)
	{
		if (prime[i] == true) continue;
		for (int j = i * i; j <= 1000000; j += i)
			prime[j] = true;
	}
	int t;
	cin >> t;
	while (t--)
	{
		int n, cnt = 0;
		cin >> n;
		for (int i = 0; i + i < n; i++)
		{
			if (prime[n / 2 - i] == false && prime[n / 2 + i] == false)
				cnt++;
		}
		cout << cnt << "\n";
	}

	return 0;
}
