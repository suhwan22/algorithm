/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-1019
 * Created     : 2025-03-09 21:40:27
 * Updated     : 2025-03-10 00:17:19
 */

#include <iostream>
#include <cmath>

using namespace std;
	
int n;
long long cnt[10];
long long arr[10] = {0, 1, 20, 300, 4000, 50000, 600000, 7000000, 80000000, 900000000};
long long zero[10] = {0, 0, 9, 189, 2889, 38889, 488889, 5888889, 68888889, 788888889};

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;

	int size = 1;
	while (n / (int)pow(10, size))
		size++;
	size--;

	for (int m = size; m >= 0; m--)
	{
		int k = n / pow(10, m);
		n %= (int)pow(10, m);
		if (size == m)
			cnt[0] = (k - 1) * arr[m] + zero[m];
		for (int i = 0; i < 10; i++)
		{
			if (i == 0 && m == size)
				continue;
			cnt[i] += k * arr[m];
			if (k > i)
				cnt[i] += pow(10, m);
			else if (k == i)
				cnt[i] += 1 + n;
		}
	}
	for (int i = 0; i < 10; i++)
		cout << cnt[i] << " ";

	return 0;
}
