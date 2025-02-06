#include <iostream>
#include <set>

using namespace std;

int n, d, k, c;
int dishes[33001];
int used[3001];
set<int> sel;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; i++)
		cin >> dishes[i];
	for (int i = 0; i < k; i++)
		dishes[i + n] = dishes[i];
	int st = 0, en = 0, cnt = 0, max = 0;
	while (en <= n + k)
	{
		if (en - st < k)
		{
			sel.insert(dishes[en]);
			used[dishes[en++]]++;
		}
		else
		{
			if (sel.find(c) == sel.end())
				cnt = sel.size() + 1;
			else
				cnt = sel.size();
			max = cnt > max ? cnt : max;
			if (--used[dishes[st]] == 0)
				sel.erase(dishes[st]);
			st++;
		}
	}
	cout << max;

	return 0;
}