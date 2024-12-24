#include <iostream>
#include <unordered_map>

using namespace std;

int n, m;
string input[500001] = {};
unordered_map<string, int> list;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> input[i];
		if (list[input[i]] != 0)
		{
			input[list[input[i]]] = "x";
			list[input[i]] = i;
		}
		else
			list[input[i]] = i;
	}
	for (int cnt = 0, i = 1; i <= m && cnt < n; i++)
	{
		if (input[i] == "x") continue;
		cout << input[i] << "\n";
		cnt++;
	}
	return 0;
}