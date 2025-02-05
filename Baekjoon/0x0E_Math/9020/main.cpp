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
		int n, k = 0;
		cin >> n;
		while (prime[n / 2 - k] != 0 || prime[n / 2 + k] != 0)
			k++;
		cout << n / 2 - k << " " << n / 2 + k << "\n";
	}
	return 0;
}