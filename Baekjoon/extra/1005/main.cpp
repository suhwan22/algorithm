/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://eventually-useful.tistory.com/11
 * Created     : 2025-03-16 19:15:53
 * Updated     : 2025-03-16 21:01:11
 */

#include <iostream>
#include <queue>

using namespace std;

int n, k, w, t;
int delay[1001];
int indegree[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
			cin >> delay[i];
		vector<int> adj[1001];
		int u, v;
		for (int i = 0; i < k; i++)
		{
			cin >> u >> v;
			indegree[v]++;
			adj[u].push_back(v);
		}
		cin >> w;
		for (int i = 1; i <= n; i++)
		{
			if (indegree[i] == 0)
				pq.push({delay[i], i});
		}
		pair<int, int> cur;
		int time = 0;
		while (!pq.empty())
		{
			cur = pq.top();
			pq.pop();
			if (cur.second == w)
				time = cur.first;
			for (int v : adj[cur.second])
			{
				if (--indegree[v] == 0)
					pq.push({cur.first + delay[v], v});
			}
		}
		cout << time << "\n";
	}

	return 0;
}
