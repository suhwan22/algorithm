#include <iostream>
#include <queue>

using namespace std;

int n, m, t;

// 원판 정보
int disk[51][52] = {};

int delAdj();
void routine();

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			cin >> disk[i][j];
	}
	int x, d, k;
	int cnt = 0;
	while (t--)
	{
		cin >> x >> d >> k;
		for (int i = x; i <= n; i += x)
		{
			for (int j = 0; j < k; j++)
			{
				if (d == 0)
				{
					for (int idx = m; idx > 0; idx--)
						disk[i][idx+1] = disk[i][idx];
					disk[i][1] = disk[i][m+1];
				}
				else if (d == 1)
				{
					for (int idx = 1; idx <= m; idx++)
						disk[i][idx-1] = disk[i][idx];
					disk[i][m] = disk[i][0];
				}
			}
		}
		int ret = delAdj();
		if (ret == 0)
			routine();
		if (cnt == n * m)
			break;
	}
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			sum += disk[i][j];
	}
	cout << sum;

	return 0;
}

// 인접한 원소를 지우기 위한 bfs함수
int delAdj()
{
	queue<pair<int, int>> q;
	pair<int, int> cur;
	int nx, ny;
	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, 1, 0, -1};
	bool visited[51][51] = {};
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (disk[i][j] != 0 && visited[i][j] == false)
			{
				visited[i][j] = true;
				vector<pair<int, int>> del;
				del.push_back({i, j});
				q.push({i,j});
				while (!q.empty())
				{
					cur = q.front();
					q.pop();
					for (int s = 0; s < 4; s++)
					{
						nx = cur.first + dx[s];
						ny = cur.second + dy[s];
						if (nx > n || nx < 1) continue;
						if (ny == 0) ny = m;
						if (ny == m+1) ny = 1;
						if (visited[nx][ny] || disk[nx][ny] != disk[cur.first][cur.second]) continue;
						visited[nx][ny] = true;
						del.push_back({nx, ny});
						q.push({nx, ny});
					}
				}
				if (del.size() != 1)
				{
					for (auto p : del)
					{
						disk[p.first][p.second] = 0;
						cnt++;
					}
				}
			}
		}
	}
	return cnt;
}

// 평균 계산 후 +1, -1 해주는 함수
void routine()
{
	int sum = 0;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (disk[i][j] == 0) continue;
			sum += disk[i][j];
			cnt++;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (disk[i][j] == 0) continue;
			if (disk[i][j] > (double)sum / cnt)
				disk[i][j] -= 1;
			else if (disk[i][j] < (double)sum / cnt)
				disk[i][j] += 1;
		}
	}
}