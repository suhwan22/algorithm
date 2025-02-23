/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-17182
 * Created     : 2025-02-23 20:24:06
 * Updated     : 2025-02-23 20:24:06
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, k, ans = 2147483647;
int dis[10][10];

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> dis[i][j];
	}
	for (int mid = 0; mid < n; mid++)
	{
		for (int st = 0; st < n; st++)
		{
			for (int en = 0; en < n; en++)
				dis[st][en] = min(dis[st][en], dis[st][mid] + dis[mid][en]);
		}
	}
	vector<int> seq;
	for (int i = 0; i < n; i++)
		if (i != k)
			seq.push_back(i);
	
	do
	{
		int temp = dis[k][seq[0]];
		for (int i = 1; i < n - 1; i++)
			temp += dis[seq[i-1]][seq[i]];
		ans = min(ans, temp);
	} while (next_permutation(seq.begin(), seq.end()));
	cout << ans;

	return 0;
}