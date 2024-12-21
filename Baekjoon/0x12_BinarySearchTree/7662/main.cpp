#include <iostream>
#include <set>

using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int t, q;
	cin >> t;
	while (t--)
	{
		cin >> q;
		multiset<int> s;
		char cmd;
		int n;
		while (q--)
		{
			cin >> cmd;
			if (cmd == 'D')
			{
				cin >> n;
				if (s.empty()) continue;
				if (n == 1)
					s.erase(prev(s.end()));
				else if (n == -1)
					s.erase(s.begin());
			}
			else if (cmd == 'I')
			{
				cin >> n;
				s.insert(n);
			}
		}
		if (s.empty())
			cout << "EMPTY\n";
		else
			cout << *(prev(s.end()))  << " "<< *(s.begin()) << "\n";
	}

	return 0;
}