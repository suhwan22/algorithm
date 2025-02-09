/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj
 * Created     : 2025-02-08 22:27:17
 * Updated     : 2025-02-09 17:56:33
 */

#include <iostream>

using namespace std;

int n;
int D[1000001];

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	int num, max = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> num;
		D[num] = D[num-1] + 1;
		if (max < D[num])
			max = D[num];
	}
	cout << n - max;

	return 0;
}
