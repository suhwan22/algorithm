#include <iostream>

using namespace std;

int prime[10001] = {1, 1, };

int main() 
{
	cin.tie(0)->sync_with_stdio(0);
	int t;
	for (int i = 2; i <= 100; i++)
	{
		for (int j = i * i; j <= 10000; j += i)
			prime[j] = 1;
	}
	cin >> t;
	while (t--)
	{
		int n, k = 1;
		cin >> n;
		if (prime[n / 2] == 0)
			cout << n / 2 << " " << n / 2 << "\n";
		else
		{
			while (1)
			{
				if (prime[n / 2 - k] == 0 && prime[n / 2 + k] == 0)
				{
					cout << n / 2 - k << " " << n / 2 + k << "\n";
					break;
				}
				k++;
			}
		}		
	}
	return 0;
}
