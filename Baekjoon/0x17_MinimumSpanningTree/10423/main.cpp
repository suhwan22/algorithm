/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-10423
 * Created     : 2025-03-04 17:53:43
 * Updated     : 2025-03-04 18:35:31
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> p(1001, -1);
tuple<int, int, int> edge[100000];
int n, m, k;

int find(int x);
bool uni(int x, int y);

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> k;
	int u, v, w;
	for (int i = 0; i < k; i++)
	{
		cin >> u;
		p[u] = 0;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v >> w;
		edge[i] = {w, u, v};
	}
	sort(edge, edge + m);
	int cnt = 0;
	int cost = 0;
	for (int i = 0; i < m; i++)
	{
		tie(w, u, v) = edge[i];
		if (!uni(u, v)) continue;
		cnt++;
		cost += w;
		if (cnt == n - k)
			break;
	}
	cout << cost;

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
