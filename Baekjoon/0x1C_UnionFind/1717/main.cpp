/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-1717
 * Created     : 2025-02-17 19:47:53
 * Updated     : 2025-02-17 22:37:09
 */

#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> p(1000001, -1);

int find(int x);
bool uni(int x, int y);

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	int a, b, c;
	while (m--)
	{
		cin >> c >> a >> b;
		if (c == 0)
			uni(a, b);
		else if (c == 1)
		{
			a = find(a);
			b = find(b);
			if (a == b)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

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
	if (p[x] > p[y])
		swap(x, y);
	if (p[x] == p[y])
		p[x]--;
	p[y] = x;
	return true;
}