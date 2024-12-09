#include <iostream>

using namespace std;

bool isPrime(int n);

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n;
	int cnt = 0;
	cin >> n;
	int input;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		if (isPrime(input))
			cnt++;
	}
	cout << cnt;
}

bool isPrime(int n)
{
	if (n == 1)
		return false;
	for (int j = 2; j * j <= n; j++)
	{
		if (n % j == 0)
			return false;
	}
	return true;
}
