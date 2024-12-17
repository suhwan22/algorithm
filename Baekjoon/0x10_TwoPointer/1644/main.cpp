#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime[4000001] = {};
vector<int> prime;
int n;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	for (int i = 2; i <= 4000000; i++)
		isPrime[i] = true;
	for (int i = 2; i < 4000000; i++)
	{
		if (!isPrime[i]) continue;
		prime.push_back(i);
		for (int j = i + i; j <= 4000000; j += i)
			isPrime[j] = false;
	}
	cin >> n;
	int st = 0, en = 0, cnt = 0, size = prime.size();
	int sum = prime[0];
	while (st <= en && prime[en] <= n && st < size && en < size)
	{
		if (sum > n)
		{
			sum -= prime[st];
			st++;
		}
		else if (sum <= n)
		{
			if (sum == n)
				cnt++;
			en++;
			sum += prime[en];
		}
	}
	cout << cnt;

	return 0;
}