#include <iostream>

using namespace std;

int gcd(int a, int b);
long long lcm(long long  a, long long  b);

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	int a, b;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		cout << lcm(a, b) << "\n";
	}

	return 0;
}

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

long long lcm(long long a, long long b)
{
	return a / gcd(a, b) * b;
}