/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj
 * Created     : 2025-04-26 21:44:42
 * Updated     : 2025-04-26 21:44:42
 */

#include <iostream>

using namespace std;

int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int m, d;
	cin >> m >> d;
	for (int i = 1; i < m; i++)
		d += month[i];
	d %= 7;
	switch(d)
	{
		case 0: cout << "SUN"; break;
		case 1: cout << "MON"; break;
		case 2: cout << "TUE"; break;
		case 3: cout << "WED"; break;
		case 4: cout << "THU"; break;
		case 5: cout << "FRI"; break;
		case 6: cout << "SAT"; break;
	}

	return 0;
}
