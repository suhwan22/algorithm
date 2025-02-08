/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj
 * Created     : 2025-02-08 16:35:14
 * Updated     : 2025-02-08 17:12:36
 */

#include <iostream>
#include <set>

using namespace std;

int n;
set<int> LIS;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	int num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		auto it = LIS.lower_bound(num);
		if (it != LIS.end())
			LIS.erase(it);
		LIS.insert(num);
	}
	cout << n - LIS.size();

	return 0;
}
