#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s, p;

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
	getline(cin, s);
	getline(cin, p);
	int j = 0;
	vector<int> f = failure(p);
	vector<int> output;
	for (int i = 0; i < (int)s.size(); i++)
	{
		while (j > 0 && s[i] != p[j]) j = f[j-1];
		if (s[i] == p[j]) j++;
		if (j == (int)p.size())
		{
			output.push_back(i - j);
			j = f[j-1];
		}
	}
	cout << output.size() << "\n";
	for (int i : output)
		cout << i + 2 << " ";

	return 0;
}
