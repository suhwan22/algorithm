#include <iostream>

using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	string s;
	cin >> s;
	int cnt = 0;
	char prev;
	int len = s.length();
	prev = s[0];
	for (int i = 1; i < len; i++)
	{
		if (prev != s[i])
		{
			cnt++;
			prev = s[i];
		}
	}
	cout << (cnt + 1) / 2;

	return 0;
}
