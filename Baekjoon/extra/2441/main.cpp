/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj
 * Created     : 2025-04-08 16:59:30
 * Updated     : 2025-04-08 17:05:59
 */

#include <iostream>

using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j < i)
				cout << " ";
			else
				cout << "*";
		}
		cout << "\n";
	}

	return 0;
}
