#include <iostream>
#include <vector>

using namespace std;

vector<int> failure(string &str)
{
	vector<int> f(str.size());
	int j = 0;
	for (int i = 1; i < (int)str.size(); i++)
	{
		while (j > 0 && str[i] != str[j]) j = f[j-1];
		if (str[i] == str[j]) f[i] = ++j;
	}
	return f;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	string s, p;
	cin >> s >> p;
	int j = 0;
	vector<int> f = failure(p);
	for (int i = 0; i < (int)s.size(); i++)
	{
		while (j > 0 && s[i] != p[j]) j = f[j-1];
		if (s[i] == p[j]) j++;
		if (j == (int)p.size())
		{
			cout << 1;
			return 0;
		}
	}
	cout << 0;

	return 0;
}
