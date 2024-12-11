#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int board[20][20] = {};
int dis[12][12] = {};
pair<int, int> start;
vector<pair<int, int>> node;
int w, h;

void calDis(vector<pair<int, int>> &node);
void dfs(int cnt, int n, int cost);
int min;
bool vis[12] = {};

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	while (1)
	{
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;
		string input;
		node.clear();
		for (int i = 0; i < h; i++)
		{
			cin >> input;
			for (int j = 0; j < w; j++)
			{
				if (input[j] == '.')
					board[i][j] = 0;
				else if (input[j] == 'x')
					board[i][j] = -1;
				else
				{
					node.push_back({i, j});
					board[i][j] = node.size();
					if (input[j] == 'o')
						start = {i, j};
				}
			}
		}
		calDis(node);
		::min = -1;
		for (int i = 0; i < 12; i++)
			vis[i] = 0;
		int st = board[start.first][start.second];
		vis[st] = true;
		for (int i = 1; i <= (int)node.size(); i++)
		{
			if (vis[i] || dis[st][i] == -1) continue;
			vis[i] = true;
			dfs(2, i, dis[st][i]);
			vis[i] = false;
		}
		cout << ::min << "\n";
	}

	return 0;
}

void calDis(vector<pair<int, int>> &node)
{
	queue<pair<int, int>> q;
	pair<int, int> cur;
	int nx, ny;
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	for (int i = 1; i <= (int)node.size(); i++)
	{
		for (int j = 1; j <= (int)node.size(); j++)
			dis[i][j] = -1;
	}
	for (int i = 0; i < (int)node.size(); i++)
	{
		bool visit[20][20] = {};
		cur = node[i];
		visit[cur.first][cur.second] = true;
		q.push({cur.first, cur.second});
		q.push({-1, -1});
		int dist = 1;
		while (!q.empty())
		{
			cur = q.front();
			q.pop();
			if (cur.first < 0)
			{
				if (q.empty())
					break;
				q.push({-1, -1});
				dist++;
				continue;
			}
			for (int j = 0; j < 4; j++)
			{
				nx = cur.first + dx[j];
				ny = cur.second + dy[j];
				if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
				if (visit[nx][ny] || board[nx][ny] == -1) continue;
				visit[nx][ny] = true;
				if (board[nx][ny] != 0)
					dis[board[node[i].first][node[i].second]][board[nx][ny]] = dist;
				q.push({nx, ny});
			}
		}
	}
}

void dfs(int cnt, int cur, int cost)
{
	if (cnt == (int)node.size())
	{
		if (::min == -1 || ::min > cost)
			::min = cost;
		return ;
	}
	for (int i = 1; i <= (int)node.size(); i++)
	{
		if (vis[i] || dis[cur][i] == -1) continue;
		vis[i] = true;
		dfs(cnt + 1, i, cost + dis[cur][i]);
		vis[i] = false;
	}
}