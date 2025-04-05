/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj
 * Created     : 2025-04-05 17:11:30
 * Updated     : 2025-04-05 18:03:16
 */

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int n, ans;
map<vector<int>, int> cnt;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	string input;

	for (int i = 0; i < n; i++)
	{
		cin >> input;
		vector<int> visited(26);
		int count = 0;
		vector<int> v(input.size());
		for (int j = 0; j < (int)input.size(); j++)
		{
			if (!visited[input[j] - 'a'])
				visited[input[j] - 'a'] = ++count;
			v[j] = visited[input[j] - 'a'];
		}
		cnt[v]++;
	}

	for (auto p : cnt)
		ans += p.second * (p.second - 1) / 2;
	cout << ans;

	return 0;
}
