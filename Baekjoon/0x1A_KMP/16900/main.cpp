/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-16900
 * Created     : 2025-02-11 21:48:32
 * Updated     : 2025-02-11 22:14:29
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> failure(string &str)
{
	vector<int> f(str.size());
	int j = 0;
	for (int i = 1; i < (int)str.size(); i++)
	{
		while (j > 0 && str[i] != str[j]) j = f[j - 1];
		if (str[i] == str[j]) f[i] = ++j;
	}
	return f;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	vector<int> f = failure(str);
	long long n;
	cin >> n;
	long long ans = 0;
	ans = n * str.size() - (n - 1) * f[str.size() - 1];
	cout << ans;

	return 0;
}
