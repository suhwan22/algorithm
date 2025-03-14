/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://eventually-useful.tistory.com/5
 * Created     : 2025-03-14 20:48:06
 * Updated     : 2025-03-14 21:35:51
 */

#include <iostream>

using namespace std;

bool isSquare[1000001];
long long st, en;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> st >> en;
	for (long long i = 2; i * i <= en; i++)
	{
		long long p = i * i;
		for (long long s = (long long)((double)st / p) * p; s <= en; s += p)
			if (s >= st)
				isSquare[s - st] = true;
	}
	int cnt = 0;
	for (long long i = 0; i <= en - st; i++)
	{
		if (isSquare[i] == false)
			cnt++;
	}
	cout << cnt;

	return 0;
}
