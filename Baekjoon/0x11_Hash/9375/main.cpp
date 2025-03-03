/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-9375
 * Created     : 2025-03-03 22:35:05
 * Updated     : 2025-03-03 22:46:43
 */

#include <iostream>
#include <unordered_map>

using namespace std;

int n, t;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> t;
	string type;
	while (t--)
	{
		unordered_map<string, int> dict;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> type >> type;
			dict[type]++;
		}
		int ans = 1;
		for (auto it : dict)
			ans *= (it.second + 1);
		cout << ans - 1 << "\n";
	}

	return 0;
}
