/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj
 * Created     : 2025-04-08 17:06:28
 * Updated     : 2025-04-08 17:08:39
 */

#include <iostream>

using namespace std;

bool student[31];

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n;
	for (int i = 0; i < 28; i++)
	{
		cin >> n;
		student[n] = true;
	}
	for (int i = 1; i <= 30; i++)
		if (!student[i])
			cout << i << "\n";

	return 0;
}
