#include <cmath>
#include <iostream>

using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	unsigned int t, x, y, k;
	cin >> t;
	while (t--)
	{
		cin >> x >> y;
		k = sqrt(y - x);
		if (pow(k, 2) == y - x)
		{
			cout << 2 * k - 1 << "\n";
			continue;
		}
		k++;
		if (pow(k, 2) -k < y - x && y - x <= pow(k, 2))
		{
			k = 2 * k - 1;
			cout << k << "\n";
			continue;
		}
		k--;
		k *= 2;
		cout << k << "\n";
	}
	return 0;
}
