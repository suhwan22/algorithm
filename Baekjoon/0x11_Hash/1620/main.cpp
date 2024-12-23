#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, int> name;
unordered_map<int, string> number;

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	string input;
	for (int i = 1; i <= n; i++)
	{
		cin >> input;
		name[input] = i;
		number[i] = input;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> input;
		if (isdigit(input[0]))
			cout << number[strtol(input.c_str(), 0, 10)] << "\n";
		else
			cout << name[input] << "\n";
	}

	return 0;
}