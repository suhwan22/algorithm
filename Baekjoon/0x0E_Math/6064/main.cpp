#include <iostream>

using namespace std;

int gcd(int n, int m);
int lcm(int n, int m);

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int t, n, m, x, y;
	cin >> t;
	while (t--)
	{
		cin >> n >> m >> x >> y;
		int l = lcm(n, m);
		if (m == y)
			y = 0;
		for (;x <= l; x += n)
		{
			if (x % m == y)
				break;
		}
		if (x > l)
			cout << "-1\n";
		else
			cout << x << "\n";
	}
	return 0;
}

int gcd(int n, int m)
{
	if (m == 0)
		return n;
	return (gcd(m, n % m));
}

int lcm(int n, int m)
{
	return n / gcd(n, m) * m;
}