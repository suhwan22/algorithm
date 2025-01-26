#include <iostream>

using namespace std;

int n;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	int st, en, s, e;
	long long ans = 0;
	cin >> st >> en;
	for (int i = 1; i < n; i++)
	{
		cin >> s >> e;
		if (s > en)
		{
			ans += en - st;
			st = s;
		}
		if (e > en)
			en = e;
	}
	ans += en - st;
	cout << ans;

	return 0;
}
