/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj
 * Created     : 2025-04-21 21:59:49
 * Updated     : 2025-04-21 22:06:16
 */

#include <iostream>
#include <set>

using namespace std;

set<int> tmp = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
set<int> s;
int q;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> q;
	string input;
	while (q--)
	{
		cin >> input;
		if (input == "empty")
			s.clear();
		else if (input == "all")
			s = tmp;
		else
		{
			int x;
			cin >> x;
			if (input == "check")
				cout << (s.find(x) == s.end() ? 0 : 1) << "\n";
			else if (input == "add" || (input == "toggle" && s.find(x) == s.end()))
				s.insert(x);
			else
				s.erase(x);
		}
	}

	return 0;
}
