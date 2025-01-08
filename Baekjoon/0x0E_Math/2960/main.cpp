#include <iostream>

using namespace std;

bool prime[1001] = {};
int n, k;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	for (int i = 2, j = 0; i <= n; i++)
	{
		if (prime[i] == true)
			continue;
		for (int t = i; t <= n; t += i)
		{
			if (prime[t] == true)
				continue;
			j++;
			prime[t] = true;
			if (j == k)
			{
				cout << t;
				return 0;
			}
		}
	}

	return 0;
}
