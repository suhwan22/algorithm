#include <iostream>
#include <set>
#include <map>

using namespace std;

int n, t;
map<int, int> ac;
set<pair<int, int>> problems;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	int num, level;
	for (int i = 0; i < n; i++)
	{
		cin >> num >> level;
		problems.insert({level, num});
		ac[num] = level;
	}
	cin >> t;
	string cmd;
	while (t--)
	{
		cin >> cmd;
		if (cmd == "recommend")
		{
			cin >> num;
			if (num == -1)
				cout << (*problems.begin()).second << "\n";
			else
				cout << (*(prev(problems.end()))).second << "\n";
		}
		else if (cmd == "add")
		{
			cin >> num >> level;
			problems.insert({level, num});
			ac[num] = level;
		}
		else if (cmd == "solved")
		{
			cin >> num;
			problems.erase(problems.find(pair<int, int>({ac[num], num})));
		}
	}

	return 0;
}
