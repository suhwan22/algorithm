#include <iostream>

using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n , count = 0, i = 2;
	cin >> n;
	if (n == 1) return 0;
	while (i * i <= n)
	{
		if (n % i == 0)
		{
			cout << i << "\n";
			n /= i;
			i = 2;
		}
		else
			i++;
	}

	if (count == 0)
		cout << n << "\n";
	return 0;
}
