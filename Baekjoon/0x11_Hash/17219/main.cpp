#include <iostream>
#include <unordered_map>

using namespace std;

int n, m;
unordered_map<string, string> pass;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	string url, pw;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> url >> pw;
		pass[url] = pw;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> url;
		cout << pass[url] << "\n";
	}

	return 0;
}