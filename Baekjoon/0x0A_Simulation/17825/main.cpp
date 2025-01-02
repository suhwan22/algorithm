#include <iostream>
#include <queue>

using namespace std;

int board[5][22] = {
	{0, 2, 4, 6, 8, -1, 12, 14, 16, 18, -2, 22, 24, 26, 28, -3, 32, 34, 36, 38, -4, 0},
	{10, 13, 16, 19, -4},
	{20, 22, 24, -4},
	{30, 28, 27, 26, -4},
	{25, 30, 35, 40, 0}
};
int dice[10];
int cur[4] = {};
int line[4] = {};
int max = 0;

int move(int &line, int &cur, int step);
void dfs(int sum, int n);
bool isValid(int sel);

vector<pair<int, int>> seq;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	for (int i = 0; i < 10; i++)
		cin >> dice[i];
	for (int i = 0; i < 4; i++)
	{
		int tcur = cur[i];
		int tline = line[i];
		int ret = move(line[i], cur[i], dice[0]);
		if (isValid(i))
		{
			seq.push_back({i, ret});
			dfs(ret, 1);
			seq.pop_back();
		}
		cur[i] = tcur;
		line[i] = tline;
	}
	cout << ::max;

	return 0;
}

void dfs(int sum, int n)
{
	if (n == 10)
	{
		if (sum > ::max)
			::max = sum;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		int tcur = cur[i];
		int tline = line[i];
		int ret = move(line[i], cur[i], dice[n]);
		if (isValid(i))
		{
			seq.push_back({i, sum + ret});
			dfs(sum + ret, n + 1);
			seq.pop_back();
		}
		cur[i] = tcur;
		line[i] = tline;
	}
}

bool isValid(int sel)
{
	if (board[line[sel]][cur[sel]] == 0)
		return true;
	for (int i = 0; i < 4; i++)
	{
		if (sel == i) continue;
		if (line[sel] == line[i] && cur[sel] == cur[i])
			return false;
	}
	return true;
}

int move(int &line, int &cur, int step)
{
	if (line == 0)
	{
		if (cur + step >= 20)
		{
			line = 4;
			cur = cur + step - 17;
		}
		else if (board[line][cur + step] < 0)
		{
			line = -board[line][cur + step];
			cur = 0;
		}
		else
			cur += step;
	}
	else if (line == 1)
	{
		if (cur + step > 3)
		{
			line = 4;
			cur = cur + step - 4;
		}
		else
			cur += step;
	}
	else if (line == 2)
	{
		if (cur + step > 2)
		{
			line = 4;
			cur = cur + step - 3;
		}
		else
			cur += step;
	}
	else if (line == 3)
	{
		if (cur + step > 3)
		{
			line = 4;
			cur = cur + step - 4;
		}
		else
			cur += step;
	}
	else if (line == 4)
	{
		if (cur + step > 3)
			cur = 4;
		else
			cur += step;
	}
	return board[line][cur];
}
