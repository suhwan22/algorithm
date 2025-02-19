/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-23326
 * Created     : 2025-02-19 17:56:45
 * Updated     : 2025-02-19 19:43:00
 */

#include <iostream>
#include <set>

using namespace std;

int n, q, pos;
set<int> attraction;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> q;
	int c, x;
	for (int i = 0; i < n; i++)
	{
		bool flag;
		cin >> flag;
		if (flag)
			attraction.insert(i);
	}
	while (q--)
	{
		cin >> c;
		if (c == 1)
		{
			cin >> x;
			if (attraction.find(x - 1) != attraction.end())
				attraction.erase(x - 1);
			else
				attraction.insert(x - 1);
		}
		else if (c == 2)
		{
			cin >> x;
			pos = (pos + x) % n;
		}
		else if (c == 3)
		{
			if (attraction.empty())
				cout << "-1\n";
			else
			{
				auto it = attraction.lower_bound(pos);
				if (it == attraction.end())
					cout << (n - pos) + *(attraction.begin()) << "\n";
				else
					cout << *it - pos << "\n";
			}
		}
	}

	return 0;
}