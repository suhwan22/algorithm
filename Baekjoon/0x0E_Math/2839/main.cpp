#include <iostream>

using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	int k = 5000;
	for (int x = 0; x <= (n / 5); x++)
	{
		for (int y = 0; y <= (n / 3); y++)
		{
			if (5 * x + 3 * y == n)
			{
				if (x + y < k)
					k = x + y;
			}
		}

	}
	if (k == 5000)
		cout << -1 << "\n";
	else
		cout << k << "\n";

	return 0;
}
