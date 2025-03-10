/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-2283
 * Created     : 2025-03-10 19:07:43
 * Updated     : 2025-03-10 19:40:54
 */

#include <iostream>

using namespace std;

int cnt[1000001][2];
int n, k;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	int input;
	for (int i = 0; i < 2 * n; i++)
	{
		cin >> input;
		cnt[input][i % 2]++;
	}
	int st = 0, en = 0, cntSt = 0, cntEn = 0, len = 0;
	while (len != k && st <= en && en < 1000001)
	{
		if (len < k)
		{
			cntEn += cnt[en][0] - cnt[en][1];
			len += cntEn;
			en++;
		}
		else
		{
			cntSt += cnt[st][0] - cnt[st][1];
			len -= cntSt;
			st++;
		}
	}
	if (len != k)
		cout << "0 0";
	else
		cout << st << " " << en;

	return 0;
}
