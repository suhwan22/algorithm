/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-19700
 * Created     : 2025-03-02 21:18:10
 * Updated     : 2025-03-02 23:35:30
 */

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int n;
pair<int, int> students[500001];
multiset<int> groups;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> students[i].first >> students[i].second;
	sort(students, students + n);
	groups.insert(1);
	for (int i = n - 2; i >= 0; i--)
	{
		auto it = groups.lower_bound(students[i].second);
		if (it != groups.begin())
			it = prev(it);
		if (*it < students[i].second)
		{
			groups.insert(*it + 1);
			groups.erase(it);
		}
		else
			groups.insert(1);
	}
	cout << groups.size();

	return 0;
}
