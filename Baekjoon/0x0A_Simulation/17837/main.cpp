#include <iostream>
#include <vector>

using namespace std;

struct piece
{
	int r;
	int c;
	int dir;
};

int n, k;
int board[13][13] = {};
piece pieces[11] = {};
vector<int> stack[13][13] = {};


int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> board[i][j];
	}
	for (int i = 1; i <= k; i++)
	{
		cin >> pieces[i].r >> pieces[i].c >> pieces[i].dir;
		stack[pieces[i].r][pieces[i].c].push_back(i);
	}
	int t = 0;
	int dx[4] = {0, 0, -1, 1};
	int dy[4] = {1, -1, 0, 0};
	int nx, ny, r, c, dir;
	bool blue = false;
	bool isEnd = false;
	for (; t <= 1000; t++)
	{
		if (isEnd)
			break;
		for (int i = 1; !isEnd && i <= k; i++)
		{
			dir = pieces[i].dir;
			r = pieces[i].r;
			c = pieces[i].c;
			nx = r + dx[dir - 1];
			ny = c + dy[dir - 1];
			if (nx < 1 || ny < 1 || nx > n || ny > n || board[nx][ny] == 2)
			{
				if (blue)
				{
					blue = false;
					continue;
				}
				else
				{
					pieces[i].dir = (dir == 1 || dir == 3) ? dir + 1 : dir - 1;
					blue = true;
					i--;
					continue;
				}
			}
			if (board[nx][ny] == 0)
			{
				int idx = 0;
				for (; idx < (int)stack[r][c].size(); idx++)
					if (stack[r][c][idx] == i)
						break;
				for (int j = idx; j < (int)stack[r][c].size(); j++)
				{
					stack[nx][ny].push_back(stack[r][c][j]);
					pieces[stack[r][c][j]].r = nx;
					pieces[stack[r][c][j]].c = ny;
				}
				for (int j = stack[r][c].size() - 1; j >= idx; j--)
					stack[r][c].pop_back();
			}
			else if (board[nx][ny] == 1)
			{
				int idx = 0;
				for (; idx < (int)stack[r][c].size(); idx++)
					if (stack[r][c][idx] == i)
						break;
				for (int j = stack[r][c].size() - 1; j >= idx; j--)
				{
					stack[nx][ny].push_back(stack[r][c][j]);
					pieces[stack[r][c][j]].r = nx;
					pieces[stack[r][c][j]].c = ny;
					stack[r][c].pop_back();
				}
			}
			blue = false;
			if ((int)stack[nx][ny].size() >= 4)
				isEnd = true;
		}
	}
	if (t > 1000)
		cout << -1;
	else
		cout << t;

	return 0;
}
