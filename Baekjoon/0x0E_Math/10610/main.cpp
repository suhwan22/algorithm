#include <iostream>
#include <algorithm>

using namespace std;
string num;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> num;
	sort(num.begin(), num.end(), greater<char>());
	int three = 0;
	for (int i = 0; i < (int)num.size(); i++)
		three = (three + (num[i] - '0')) % 3;
	if (three != 0 || num[num.size() - 1] != '0')
		cout << -1;
	else
		cout << num;

	return 0;
}
