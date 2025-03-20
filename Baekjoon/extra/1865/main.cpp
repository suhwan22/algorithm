/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://eventually-useful.tistory.com/14
 * Created     : 2025-03-17 18:30:06
 * Updated     : 2025-03-18 18:29:07
 */

#include <iostream>
#include <vector>
#include <tuple>

#define INF 1000000000

using namespace std;

int tc, n, m, w;
vector<tuple<int, int, int>> edge;
int dis[501];
bool en;

void bellmanFord();

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> tc;
	while (tc--)
	{
		cin >> n >> m >> w;
		int s, e, t;
		edge.clear();
		for (int i = 0; i < m; i++)
		{
			cin >> s >> e >> t;
			edge.push_back({s, e, t});
			edge.push_back({e, s, t});
		}
		for (int i = 0; i < w; i++)
		{
			cin >> s >> e >> t;
			edge.push_back({s, e, -t});
		}
		bellmanFord();
		if (en)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}

void bellmanFord()
{
	for (int i = 1; i <= n; i++)
		dis[i] = INF;
	int from, to, w;
	for (int i = 1; i <= n; i++)
	{
		en = false;
		for (int j = 0; j < (int)edge.size(); j++)
		{
			tie(from, to, w) = edge[j];
			if (dis[to] > dis[from] + w)
			{
				dis[to] = dis[from] + w;
				en = true;
			}
		}
		if (!en)
			return;
	}
}