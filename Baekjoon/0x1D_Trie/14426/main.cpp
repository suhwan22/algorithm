/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj
 * Created     : 2025-02-27 21:37:21
 * Updated     : 2025-02-27 21:48:36
 */

#include <iostream>

using namespace std;

const int ROOT = 1;
const int MAX = 10000 * 500 + 5;
int unused = 2;
int nxt[MAX][26];
bool chk[MAX];

void insert(string &str);
bool find(string &str);
bool prefixFind(string &str);

int n, m;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < 26; j++)
			nxt[i][j] = -1;

	cin >> n >> m;
	string input;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		insert(input);
	}
	int cnt = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> input;
		if (prefixFind(input))
			cnt++;
	}
	cout << cnt;

	return 0;
}

void insert(string &str)
{
	int cur = ROOT;
	for (char c : str)
	{
		if (nxt[cur][c - 'a'] == -1)
			nxt[cur][c - 'a'] = unused++;
		cur = nxt[cur][c - 'a'];
	}
	chk[cur] = true;
}

bool find(string &str)
{
	int cur = ROOT;
	for (char c : str)
	{
		if (nxt[cur][c - 'a'] == -1)
			return false;
		cur = nxt[cur][c - 'a'];
	}
	return chk[cur];
}

bool prefixFind(string &str)
{
	int cur = ROOT;
	for (char c : str)
	{
		if (nxt[cur][c - 'a'] == -1)
			return false;
		cur = nxt[cur][c - 'a'];
	}
	return true;
}