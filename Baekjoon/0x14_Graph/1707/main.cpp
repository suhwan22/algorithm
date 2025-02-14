/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj
 * Created     : 2025-02-14 19:08:11
 * Updated     : 2025-02-14 20:06:05
 */

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int k, n, m;
int color[20001] = {};
vector<int> adj[20001];

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> k;
	while (k--)
	{
		cin >> n >> m;
		int u, v;
		for (int i = 1; i <= n; i++)
			adj[i].clear();
		for (int i = 0; i < m ; i++)
		{
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		bzero(color, sizeof(color));
		bool flag = true;
		for (int i = 1; i <= n && flag; i++)
		{
			if (color[i] != 0) continue;
			color[i] = 1;
			queue<int> q;
			q.push(i);
			int cur;
			while (!q.empty() && flag)
			{
				cur = q.front();
				q.pop();
				for (int k : adj[cur])
				{
					if (color[k] == color[cur])
						flag = false;
					if (color[k] != 0) continue;
					color[k] = color[cur] == 1 ? 2 : 1;
					q.push(k);
				}
			}
		}
		if (flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}
