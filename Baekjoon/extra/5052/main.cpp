/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-5052
 * Created     : 2025-03-22 01:02:22
 * Updated     : 2025-03-22 01:29:40
 */

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int ROOT = 1;
const int MAX = 100000 * 10 + 5;
int unused = 2;
int nxt[MAX][10];
bool chk[MAX];

int tc;
int n;

bool insert(string &str);

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> tc;
	while (tc--)
	{
		bzero(nxt, sizeof(nxt));
		bzero(chk, sizeof(chk));
		unused = 2;
		cin >> n;
		vector<string> number(n);
		bool flag = true;
		for (int i = 0; i < n; i++)
			cin >> number[i];
		sort(number.begin(), number.end());
		for (int i = 0; i < n; i++)
			if (!insert(number[i]))
				flag = false;
		if (!flag)
			cout << "NO\n";
		else
			cout << "YES\n";
	}

	return 0;
}

bool insert(string &str)
{
	int cur = ROOT;
	for (char n : str)
	{
		if (chk[cur])
			return false;
		if (nxt[cur][n - '0'] == 0)
			nxt[cur][n - '0'] = unused++;
		cur = nxt[cur][n - '0'];
	}
	chk[cur] = true;
	return true;
}