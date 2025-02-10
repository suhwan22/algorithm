/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-7453
 * Created     : 2025-02-09 19:06:10
 * Updated     : 2025-02-10 23:17:15
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
long long cnt = 0;
int arr[4][4000];
vector<int> a;
vector<int> b;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 4; j++)
			cin >> arr[j][i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a.push_back(arr[0][i] + arr[1][j]);
			b.push_back(arr[2][i] + arr[3][j]);
		}
	}
	sort(a.begin(), a.end());
	a.push_back(2147483647);
	sort(b.begin(), b.end());
	b.push_back(2147483647);

	for (int i = 0; i < n * n; i++)
	{
		int st1 = 0, en1 = n * n;
		while (st1 < en1)
		{
			int mid = (st1 + en1) / 2;
			int sum = a[i] + b[mid];
			if (sum < 0)
				st1 = mid + 1;
			else
				en1 = mid;
		}
		int st2 = 0, en2 = n * n;
		while (st2 < en2)
		{
			int mid = (st2 + en2) / 2;
			int sum = a[i] + b[mid];
			if (sum <= 0)
				st2 = mid + 1;
			else
				en2 = mid;
		}
		cnt += st2 - st1;
	}
	cout << cnt;

	return 0;
}