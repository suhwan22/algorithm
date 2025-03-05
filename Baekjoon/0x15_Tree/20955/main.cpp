/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-20955
 * Created     : 2025-03-06 00:00:16
 * Updated     : 2025-03-06 00:07:49
 */

#include <iostream>

using namespace std;

int n, m;
int p[100001];

int find(int x);
bool uni(int x, int y);

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		p[i] = -1;
	int u, v;
	int cnt = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		if (uni(u, v))
			cnt++;
	}
	for (int i = 1; i <= n; i++)
		if (p[i] < 0)
			m++;
	cout << m - cnt - 1;

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