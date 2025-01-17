#include <iostream>

using namespace std;

int n;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	if (n == 1 || n == 2)
	{
		cout << n;
		return 0;
	}
	int a = 1, b = 2;
	int ans;
	for (int i = 3; i <= n; i++)
	{
		ans = (a + b) % 15746;
		a = b;
		b = ans;	
	}
	cout << ans;

	return 0;
}
