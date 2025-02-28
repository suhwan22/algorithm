/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-9202
 * Created     : 2025-02-28 18:00:05
 * Updated     : 2025-02-28 18:00:05
 */

#include <iostream>

using namespace std;

const int MAX = 300000 * 8 + 8;
const int ROOT = 1;
int unused = 2;
int nxt[MAX][26];
char chk[MAX];

int n, m = 1, t;
char board[4][4];
bool visited[4][4];
int score, cnt;
string longword;

void insert(string &str);
int getScore(int len);
void dfs(int x, int y, int cur, string &str);

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < 26; j++)
			nxt[i][j] = -1;
	}
	
	cin >> n;
	string input;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		insert(input);	
	}
	cin >> t;
	for (; m <= t; m++)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				cin >> board[i][j];
				visited[i][j] = false;
			}
		}
		score = 0;
		cnt = 0;
		longword = "";
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				string str;
				int node = nxt[ROOT][board[i][j] - 'A'];
				if (node == -1) continue;
				visited[i][j] = true;
				str.push_back(board[i][j]);
				dfs(i, j, node, str);
				visited[i][j] = false;
				str.pop_back();
			}
		}
		cout << score << " " << longword << " " << cnt << "\n";
	}

	return 0;
}

int getScore(int len)
{
	if (len <= 2)
		return 0;
	else if (len <= 4)
		return 1;
	else if (len <= 6)
		return len - 3;
	else if (len == 7)
		return 5;
	else
		return 11;
}

void dfs(int x, int y, int cur, string &str)
{
	if (chk[cur] != 0 && chk[cur] <= m)
	{
		chk[cur] = m + 1;
		cnt++;
		if (longword.length() < str.length())
			longword = str;
		else if (longword.length() == str.length() && longword > str)
			longword = str;
		score += getScore(str.length());
	}
	int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
	int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
	int nx, ny;
	for (int i = 0; i < 8; i++)
	{
		nx = x + dx[i];
		ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) continue;
		if (visited[nx][ny]) continue;
		int node = nxt[cur][board[nx][ny] - 'A'];
		if (node == -1) continue;
		visited[nx][ny] = true;
		str.push_back(board[nx][ny]);
		dfs(nx, ny, node, str);
		str.pop_back();
		visited[nx][ny] = false;
	}
}

void insert(string &str)
{
	int cur = ROOT;
	for (char c : str)
	{
		if (nxt[cur][c - 'A'] == -1)
			nxt[cur][c - 'A'] = unused++;
		cur = nxt[cur][c - 'A'];
	}
	chk[cur] = 1;
}
