/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://eventually-useful.tistory.com/6
 * Created     : 2025-03-15 16:35:00
 * Updated     : 2025-03-15 17:19:39
 */

#include <iostream>
#include <vector>

using namespace std;

int n;
long long r;
vector<pair<int, int>> adj[100001];

long long dfs(int p, int cur, long long dist);

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	int u, v, w;
	for (int i = 0; i < n; i++)
	{
		cin >> u;
		while (1)
		{
			cin >> v;
			if (v == -1)
				break;
			cin >> w;
			adj[u].push_back({v, w});
		}
	}
	dfs(-1, 1, 0);
	cout << r;

	return 0;
}

long long dfs(int p, int cur, long long dist)
{
	long long depth = 0;
	for (auto edge : adj[cur])
	{
		if (edge.first == p)
			continue;
		long long ret = dfs(cur, edge.first, edge.second);
		if (depth + ret > r)
			r = depth + ret;
		depth = max(depth, ret);
	}
	return dist + depth;
}
