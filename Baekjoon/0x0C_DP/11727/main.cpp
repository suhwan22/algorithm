/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-11727
 * Created     : 2025-03-05 19:10:35
 * Updated     : 2025-03-05 19:10:35
 */

#include <iostream>

using namespace std;

int n;
int D[1001] = {0, 1, 3, };

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 3; i <= n; i++)
		D[i] = (D[i-1] + 2 * D[i-2]) % 10007;
	cout << D[n];

	return 0;
}
