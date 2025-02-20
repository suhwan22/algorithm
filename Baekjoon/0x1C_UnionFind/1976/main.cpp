/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj
 * Created     : 2025-02-20 21:40:14
 * Updated     : 2025-02-20 21:48:45
 */

#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> p(201, -1);

int find(int x);
bool uni(int x, int y);

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	int k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> k;
			if (k == 1)
				uni(i, j);
		}
	}
	cin >> k;
	int root = find(k);
	for (int i = 1; i < m; i++)
	{
		cin >> k;
		if (root != find(k))
		{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";

	return 0;
}

int find(int x)
{
	if (p[x] < 0)
		return x;
	return p[x] = find(p[x]);
}

bool uni(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return false;
	p[y] = x;
	return true;
}