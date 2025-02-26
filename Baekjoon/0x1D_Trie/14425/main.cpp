/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-14425
 * Created     : 2025-02-26 18:27:35
 * Updated     : 2025-02-26 19:06:12
 */

#include <iostream>
#include <string>

using namespace std;

const int root = 1;
int unused = 2;
const int mx = 10000 * 500 + 5;
int nxt[mx][26];
bool chk[mx];
int n, m;

void insert(string &str);
bool find(string &str);


int main()
{
	cin.tie(0)->sync_with_stdio(0);

	for (int i = 0; i < mx; i++)
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
		if (find(input))
			cnt++;
	}
	cout << cnt;


	return 0;
}

void insert(string &str)
{
	int cur = root;
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
	int cur = root;
	for (char c : str)
	{
		if (nxt[cur][c - 'a'] == -1)
			return false;
		cur = nxt[cur][c - 'a'];
	}
	return chk[cur];
}