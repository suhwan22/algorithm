/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-2065
 * Created     : 2025-02-22 19:06:33
 * Updated     : 2025-02-22 22:15:37
 */

#include <iostream>
#include <queue>

using namespace std;

int n, m, t;
int seq[10000];
queue<pair<int, int>> stop[2];

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> m >> t >> n;
			
	int time;
	string p;
	for (int i = 0; i < n; i++)
	{
		cin >> time >> p;
			stop[p == "left" ? 0 : 1].push({i, time});
	}

	int pos = 0;
	time = 0;
	while (!stop[0].empty() || !stop[1].empty())
	{
		int cnt = 0;
		for (; cnt < m; cnt++)
		{
			if (stop[pos].empty() || stop[pos].front().second > time) break;
			seq[stop[pos].front().first] = time + t;
			stop[pos].pop();
		}
		if (cnt == 0)
		{
			if (stop[!pos].empty() || (!stop[pos].empty() && stop[pos].front().second <= stop[!pos].front().second))
				time = stop[pos].front().second;
			else
			{
				time += t + max(0, stop[!pos].front().second - time);
				pos = !pos;
			}
		}
		else
		{
			time += t;
			pos = !pos;
		}
	}
	for (int i = 0; i < n; i++)
		cout << seq[i] << "\n";

	return 0;
}
