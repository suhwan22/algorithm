/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-2461
 * Created     : 2025-02-06 23:25:56
 * Updated     : 2025-02-06 23:25:56
 */

#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <limits>

using namespace std;

int n, m;
int issued[1001];
set<int> sel;
vector<pair<int, int>> students;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	int w;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> w;
			students.push_back({w, i});
		}
	}
	sort(students.begin(), students.end());
	int st = 0, en = 0;
	long long min = numeric_limits<long long>::max();
	int len = students.size();
	while (en <= len)
	{
		if ((int)sel.size() < n)
		{
			sel.insert(students[en].second);
			issued[students[en].second]++;
			en++;
		}
		else
		{
			int d = students[en-1].first - students[st].first;
			min = d < min ? d : min;
			if (--issued[students[st].second] == 0)
				sel.erase(students[st].second);
			st++;
		}
	}
	cout << min;

	return 0;
}
