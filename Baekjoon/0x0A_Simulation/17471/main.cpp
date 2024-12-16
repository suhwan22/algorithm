#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int board[11] = {};
int n;
vector<int> adj[11] = {};

int isGroup(vector<int> &sel);

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> board[i];
	int m, v;
	for (int i = 1; i <= n; i++)
	{
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			cin >> v;
			adj[i].push_back(v);
		}
	}

	int min = -1;
	for (int i = 1; i <= n / 2; i++)
	{
		vector<bool> seq;
		for (int j = 0; j < n; j++)
			seq.push_back(j < i ? 0 : 1);
		do
		{
			vector<int> a, b;
			for (int j = 0; j < n; j++)
			{
				if (seq[j] == 0)
					a.push_back(j + 1);
				else
					b.push_back(j + 1);
			}
			int sumA = isGroup(a);
			int sumB = isGroup(b);
			if (sumA >= 0 && sumB >= 0)
			{
				int sum = sumA - sumB >= 0 ? sumA - sumB : sumB - sumA;
				if (min == -1 || min > sum)
					min = sum;
			}
		} while (next_permutation(seq.begin(), seq.end()));
	}
	cout << min;
	return 0;
}

int isGroup(vector<int> &sel)
{
	queue<int> q;
	int cur, cnt = 0;
	bool s[11] = {};
	q.push(sel[0]);
	while (!q.empty())
	{
		cur = q.front();
		q.pop();
		if (s[cur] || find(sel.begin(), sel.end(), cur) == sel.end())
			continue;
		cnt++;
		s[cur] = true;
		for (int v : adj[cur])
		{
			if (s[v]) continue;
			q.push(v);
		}
	}
	if (cnt != (int)sel.size())
		return -1;
	int sum = 0;
	for (int i : sel)
		sum += board[i];
	return sum;
}