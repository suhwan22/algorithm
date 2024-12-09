#include <iostream>

using namespace std;

int arr[123456 * 2 + 1] = {};

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	for (int i = 2; i * i<= 123456 * 2; i++)
	{
		for (int j = i * i; j < 123456 * 2 + 1; j += i)
			arr[j] = 1;
	}
	while (1)
	{
		int n, sum = 0;
		cin >> n;
		if (n == 0)
			break;
		else if (n == 1)
			cout << 1 << "\n";
		else
		{
			for (int k = n + 1; k <= 2 * n; k++)
			{
				if (arr[k] == 0)
					sum++;
			}		
			cout << sum << "\n";
		}

	}
	return 0;
}
