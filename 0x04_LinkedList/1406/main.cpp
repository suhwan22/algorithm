#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	list<char> ed;
	string s1;
	cin >> s1;
	for (char c : s1)
		ed.push_back(c);
	//ed.push_back(' ');
	auto t = ed.end();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char sel;
		cin >> sel;
		switch (sel)
		{
		case'L': if (t == ed.begin()) break; t--; break;
		case'D': if (t == ed.end()) break; t++; break;
		case'B': if (t == ed.begin()) break;
			t--; t = ed.erase(t); break;
		case'P': char c1; cin >> c1; ed.insert(t, c1); break;
		}
	}
	//ed.pop_back();
	t = ed.begin();
	for (int i = 0; i < (int)ed.size(); i++)
	{
		cout << *(t++);
	}
	return 0;
}