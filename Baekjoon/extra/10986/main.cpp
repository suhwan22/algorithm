/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://eventually-useful.tistory.com/13
 * Created     : 2025-03-18 18:29:19
 * Updated     : 2025-03-18 20:53:59
 */

#include <iostream>

using namespace std;

long long cntRemain[1000];
int n, m;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	int input, pre = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> input;
		pre = (pre + input) % m;
		cntRemain[pre]++;
	}

	long long cnt = cntRemain[0];
	for (int i = 0; i < m; i++)
		cnt += cntRemain[i] * (cntRemain[i] - 1) / 2;

	cout << cnt;
	return 0;
}