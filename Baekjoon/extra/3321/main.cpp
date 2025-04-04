/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-3321
 * Created     : 2025-04-03 15:48:11
 * Updated     : 2025-04-05 00:26:35
 */

#include <iostream>
#include <algorithm>
#include <stack>
#include <map>

using namespace std;

int n, m, ans = 0;
vector<pair<int, int>> histogram;
stack<pair<int, int>> s;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	histogram.resize(m);
	for (int i = 0; i < m; i++)
		histogram[i] = {0, i};

	string input;
	vector<pair<int, int>> temp(m);
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		int idx = 0;
		for (int j = m - 1; j >= 0; j--)
		{
			if (input[histogram[j].second] == '0')
				temp[idx++] = {0, histogram[j].second};
			else
				temp[j + idx] = {histogram[j].first + 1, histogram[j].second};
		}
		histogram = temp;
		for (int j = 0; j <= m; j++)
		{
			pair<int, int> cur = {0, j};
			while (!s.empty() && (j == m || histogram[j].first < s.top().first))
			{
				cur = s.top();
				s.pop();
				if (ans < cur.first * (j - cur.second))
					ans = cur.first * (j - cur.second);
			}
			if (j != m && histogram[j].first != 0 && (s.empty() || s.top().first < histogram[j].first))
				s.push({histogram[j].first, cur.second});
		}
	}
	cout << ans;

	return 0;
}
