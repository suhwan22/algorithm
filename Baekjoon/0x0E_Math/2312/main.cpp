#include <iostream>
#include <vector>

using namespace std;

int n, t;
bool prime[100001] = {1, 1, };
vector<int> parr;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	for (int i = 1; i <= 100000; i++)
	{
		if (prime[i]) continue;
		for (int j = i * i; j <= 100000; j += i)
			prime[j] = true;
	}
	for (int i = 2; i <= 100000; i++)
		if (prime[i] == false)
			parr.push_back(i);
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int p : parr)
		{
			int cnt = 0;
			while (n % p == 0)
			{
				n /= p;
				cnt++;
			}
			if (cnt > 0)
				cout << p << " " << cnt << "\n";
		}
	}

	return 0;
}