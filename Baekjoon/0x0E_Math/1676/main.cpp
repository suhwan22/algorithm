#include <iostream>

using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n, cnt = 0;
	cin >> n;
	for (int i = 5; i <= n; i += 5)
	{
		int j = i;
		while (j % 5 == 0)
		{
			j /= 5;
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}
