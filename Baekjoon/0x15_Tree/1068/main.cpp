/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-1068
 * Created     : 2025-02-15 22:07:32
 * Updated     : 2025-02-15 23:04:40
 */


#include <iostream>
#include <vector>

using namespace std;

int n, d, root, leaf;
vector<int> child[51];

void dfs(int p);

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	int p;
	for (int i = 1; i <= n; i++)
	{
		cin >> p;
		p++;
		child[p].push_back(i);
	}
	cin >> d;
	d++;
	dfs(child[0][0]);
	cout << leaf;

	return 0;
}

void dfs(int p)
{
	if (p == d)
		return;
	int cnt = 0;
	for (int i = 0; i < (int)child[p].size(); i++)
	{
		if (child[p][i] == d) continue;
		dfs(child[p][i]);
		cnt++;
	}
	if (cnt == 0)
		leaf++;
}