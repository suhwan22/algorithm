/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-2887
 * Created     : 2025-03-04 19:05:27
 * Updated     : 2025-03-04 19:05:27
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

vector<int> p(100000, -1);
pair<int, int> xarr[100000];
pair<int, int> yarr[100000];
pair<int, int> zarr[100000];
tuple<int, int, int> edge[300000];
int n;

int find(int x);
bool uni(int x, int y);

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	int x, y, z;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y >> z;
		xarr[i] = {x, i};
		yarr[i] = {y, i};
		zarr[i] = {z, i};
	}
	sort(xarr, xarr + n);
	sort(yarr, yarr + n);
	sort(zarr, zarr + n);
	for (int i = 0; i < n - 1; i++)
		edge[i] = {xarr[i+1].first - xarr[i].first, xarr[i+1].second, xarr[i].second};
	for (int i = 0; i < n - 1; i++)
		edge[n - 1 + i] = {yarr[i+1].first - yarr[i].first, yarr[i+1].second, yarr[i].second};
	for (int i = 0; i < n - 1; i++)
		edge[2 * (n - 1) + i] = {zarr[i+1].first - zarr[i].first, zarr[i+1].second, zarr[i].second};
	sort(edge, edge + 3 * (n - 1));
	
	int cost = 0;
	int cnt = 0;
	int w, u, v;
	for (int i = 0; i < 3 * (n - 1); i++)
	{
		tie(w, u, v) = edge[i];
		if (!uni(u, v)) continue;
		cost += w;
		cnt++;
		if (cnt == n - 1)
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