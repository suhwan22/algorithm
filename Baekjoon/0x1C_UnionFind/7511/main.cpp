/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-7511
 * Created     : 2025-02-18 19:07:48
 * Updated     : 2025-02-18 19:28:30
 */

#include <iostream>
#include <vector>

using namespace std;

int t, n, m, k;

int find(vector<int> &p, int x);
bool uni(vector<int> &p, int x, int y);

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cin >> n >> k;
		vector<int> p(n, -1);
		int a, b;
		for (int j = 0; j < k; j++)
		{
			cin >> a >> b;
			uni(p, a, b);
		}
		cin >> m;
		cout << "Scenario " << i << ":\n";
		for (int j = 0; j < m; j++)
		{
			cin >> a >> b;
			if (find(p, a) == find(p, b))
				cout << "1\n";
			else
				cout << "0\n";
		}
		cout << "\n";
	}

	return 0;
}

int find(vector<int> &p, int x)
{
	if (p[x] < 0)
		return x;
	p[x] = find(p, p[x]);
	return p[x];
}

bool uni(vector<int> &p, int x, int y)
{
	x = find(p, x);
	y = find(p, y);
	if (x == y)
		return false;
	if (p[x] > p[y])
		swap(x, y);
	if (p[x] == p[y])
		p[x]--;
	p[y] = x;
	return true;
}