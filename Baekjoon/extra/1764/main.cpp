/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj
 * Created     : 2025-04-22 21:08:34
 * Updated     : 2025-04-22 21:12:38
 */

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<string, int> dict;
vector<string> ans;
int n, m;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	string input;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		dict[input] = 1;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> input;
		if (dict[input] == 1)
			ans.push_back(input);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (string output : ans)
		cout << output << "\n";

	return 0;
}
