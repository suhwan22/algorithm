/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj
 * Created     : 2025-04-25 00:47:12
 * Updated     : 2025-04-25 01:29:35
 */

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int n, m, max;
int cnt[10001];
bool visited[10001];
vector<int> adj[10001];
queue<int> q;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	int u, v;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
	{
		bzero(visited, sizeof(visited));
		visited[i] = true;
		q.push(i);
		int cur;
		while (!q.empty())
		{
			cur = q.front();
			q.pop();
			for (int nxt : adj[cur])
			{
				if (visited[nxt]) continue;
				visited[nxt] = true;
				q.push(nxt);
				cnt[i]++;
			}
		}
		if (cnt[i] > ::max)
			::max = cnt[i];
	}
	for (int i = 1; i <= n; i++)
		if (cnt[i] == ::max)
			cout << i << " ";

	return 0;
}