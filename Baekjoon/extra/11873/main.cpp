/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-11873
 * Created     : 2025-04-02 19:01:55
 * Updated     : 2025-04-02 19:01:55
 */

#include <iostream>
#include <cstring>
#include <stack>
#include <map>

using namespace std;

int histogram[1001];
stack<pair<int, int>> s;
int n, m;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	while (1)
	{
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		int ans = 0;
		bzero(histogram, sizeof(histogram));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int k;
				cin >> k;
				if (k == 0)
					histogram[j] = 0;
				else
					histogram[j] = histogram[j] + 1;
			}
			for (int x = 0; x <= m; x++)
			{
				pair<int, int> cur = {0, x};
				while (!s.empty() && (x == m || histogram[x] < s.top().first))
				{
					cur = s.top();
					s.pop();
					if (ans < cur.first * (x - cur.second))
						ans = cur.first * (x - cur.second);
				}
				if (x != m && histogram[x] != 0 && (s.empty() || s.top().first < histogram[x]))
					s.push({histogram[x], cur.second});
			}
		}
		cout << ans << "\n";
	}

	return 0;
}
