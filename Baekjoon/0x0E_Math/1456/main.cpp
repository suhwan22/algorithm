#include <iostream>
#include <cmath>

using namespace std;

long long a, b;
bool prime[10000001] = {};

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> a >> b;
	int cnt = 0;
	for (long long i = 2; i <= 10000000; i++)
	{
		if (prime[i] == false)
		{
			for (int j = i + i; j <= 10000000; j += i)
				prime[j] = true;
			for (long long k = i * i; k <= b; k *= i)
			{
				if (a <= k)
					cnt++;
				if (k > b / i)
					break;
			}
			}
	}
	cout << cnt;

	return 0;
}
