/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj
 * Created     : 2025-04-08 16:42:10
 * Updated     : 2025-04-08 16:47:07
 */

#include <iostream>
#include <algorithm>

using namespace std;

int arr[9];
int seq[9] = {0, 0, 0, 0, 0, 0, 0, 1, 1};

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	for (int i = 0; i < 9; i++)
		cin >> arr[i];
	sort(arr, arr + 9);
	do
	{
		int sum = 0;
		for (int i = 0; i < 9; i++)
			if (seq[i] == 0)
				sum += arr[i];
		if (sum == 100)
		{
			for (int i = 0; i < 9; i++)
				if (seq[i] == 0)
					cout << arr[i] << "\n";
			break;
		}
	} while (next_permutation(seq, seq + 9));
	

	return 0;
}
