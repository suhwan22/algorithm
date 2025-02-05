#include <iostream>
#include <vector>

using namespace std;

int count = 0;
int cnt, k = 0;
vector<int> ans;

void dfs(int idx, int len);

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> cnt;
	if (cnt > 1022)
		cout << -1 << "\n";
	else
	{
		for (int len = 1; len <= 10; len++)
			dfs(10, len);
	}

	return 0;
}

void dfs(int idx, int len)
{
	if (k > cnt)
		return;
	if ((int)ans.size() == len)
	{
		if (k == cnt)
		{
			for (int num : ans)
				cout << num;
		}
		k++;
		return;
	}
	for (int i = 0; i < idx; i++)
	{
		ans.push_back(i);
		dfs(i, len);
		ans.pop_back();
	}
}