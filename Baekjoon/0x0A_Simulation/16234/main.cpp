#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int board[100][100] = {};
int sum[2501] = {};

int n, l, r;

bool isBind(int x1, int y1, int x2, int y2);

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> l >> r;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cin >> board[i][j];
  }

  queue<pair<int, int>> q;
  pair<int, int> cur;
  int nx, ny;
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};

  int round = 0;
  while (1)
  {
    int cnt = 0;
    bool visit[50][50] = {};
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (visit[i][j] == false)
        {
          int sum = 0;
          vector<pair<int, int>> bind;
          q.push({i, j});
          visit[i][j] = true;
          while (!q.empty())
          {
            cur = q.front();
            q.pop();
            sum += board[cur.first][cur.second];
            bind.push_back(cur);
            for (int k = 0; k < 4; k++)
            {
              nx = cur.first + dx[k];
              ny = cur.second + dy[k];
              if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
              if (visit[nx][ny] || !isBind(cur.first, cur.second, nx, ny)) continue;
              visit[nx][ny] = true;
              q.push({nx, ny});
            }
          }
          if (bind.size() <= 1)
            continue;
          int avg = sum / (int)bind.size();
          cnt++;
          for (auto p : bind)
            board[p.first][p.second] = avg;
        }
      }
    }
    if (cnt == 0)
      break;
    round++;
  }

  cout << round;

  return 0;
}

bool isBind(int x1, int y1, int x2, int y2)
{
  return ((int)abs(board[x1][y1] - board[x2][y2]) <= r) && ((int)abs(board[x1][y1] - board[x2][y2]) >= l);
}