#include <iostream>
#include <algorithm>

using namespace std;

int n;
int pos[50] = {};
int posCnt = 0;
int neg[50] = {};
int negCnt = 0;
bool zero = false;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	int input;
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		if (input == 0)
			zero = true;
		else if (input == 1)
			ans++;
		else if (input > 0)
			pos[posCnt++] = input;
		else
			neg[negCnt++] = input;
	}
	sort(neg, neg + negCnt);
	sort(pos, pos + posCnt);
	for (int i = 0; i + 1 < negCnt; i += 2)
		ans += neg[i] * neg[i+1];
	for (int i = posCnt - 1; i - 1 >= 0; i -= 2)
		ans += pos[i] * pos[i-1];
	if (posCnt % 2 == 1)
		ans += pos[0];
	if (negCnt % 2 == 1 && !zero)
		ans += neg[negCnt - 1];
	cout << ans;

	return 0;
}