/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj
 * Created     : 2025-04-15 23:39:32
 * Updated     : 2025-04-16 00:02:04
 */

#include <iostream>

using namespace std;

char table[5][15];

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	for (int i = 0; i < 5; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < (int)input.size(); j++)
			table[i][j] = input[j];
	}
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (table[j][i] == 0) continue;
			cout << table[j][i];
		}
	}

	return 0;
}
