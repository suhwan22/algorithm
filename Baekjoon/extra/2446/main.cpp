/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj
 * Created     : 2025-05-07 21:55:42
 * Updated     : 2025-05-07 22:05:04
 */

#include <iostream>

using namespace std;

int n;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
			cout << " ";
		for (int j = 0; j < 2 * (n - i) - 1; j++)
			cout << "*";
		cout << "\n";
	}
	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
			cout << " ";
		for (int j = 0; j < 2 * (n - i) - 1; j++)
			cout << "*";
		cout << "\n";
	}

	return 0;
}
