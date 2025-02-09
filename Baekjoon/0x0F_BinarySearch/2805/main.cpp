/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-2805
 * Created     : 2025-02-09 19:02:23
 * Updated     : 2025-02-09 19:03:32
 */

#include <iostream>
#include <algorithm>

using namespace std;

long long n, m;
long long trees[1000000];

bool logging(int limit);

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> trees[i];
	sort(trees, trees + n);
	int st = 0, en = trees[n - 1], mid;
	while (st < en)
	{
		mid = (st + en + 1) / 2;
		bool flag = logging(mid);
		if (flag)
			st = mid;
		else
			en = mid - 1;
	}
	cout << st;

	return 0;
}

bool logging(int limit)
{
	long long v = 0;
	for (int i = 0; i < n; i++)
	{
		if (trees[i] > limit)
		{
			v += trees[i] - limit;
			if (v >= m)
				return v;
		}
	}
	return false;
}
