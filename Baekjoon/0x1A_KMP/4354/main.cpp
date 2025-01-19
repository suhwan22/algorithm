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
	while (1)
	{
		string s;
		cin >> s;
		if (s == ".")
			return 0;
		vector<int> f = failure(s);
		int m = s.size() - f[s.size() - 1];
		if (s.size() % m == 0)
			cout << s.size() / m << "\n";
		else
			cout << "1\n";
	}

	return 0;
}
