/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj
 * Created     : 2025-04-30 00:55:32
 * Updated     : 2025-04-30 01:09:03
 */

#include <iostream>

using namespace std;

long long ans;

long long mypow(long long n, int k);

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int len;
	cin >> len;
	string input;
	cin >> input;
	for (int i = 0; i < len; i++)
		ans = (ans + (input[i] - 'a' + 1) * mypow(31, i)) % 1234567891;
	cout << ans;

	return 0;
}

long long mypow(long long n, int k)
{
	long long ret = 1;
	for (int i = 0; i < k; i++)
		ret = (ret * n) % 1234567891;
	return ret;
}