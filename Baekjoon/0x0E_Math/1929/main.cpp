#include <iostream>

using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int m, n;
	int t;
	cin >> m >> n;
	for (int i = m; i <= n; i++)
	{
		t = 0;
		for (int k = 2; k * k <= i ; k++)
		{
			if (i % k == 0)
			{
				t++;
				break;
			}
		}
		if (t == 0 && i != 1)
			cout << i << "\n";
	}
	return 0;
}
