#include <iostream>
#include <queue>

using namespace std;

int n, m;
int r, c;
int dir;
int board[50][50] = {};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  cin >> r >> c >> dir;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
      cin >> board[i][j];
  }

  queue<pair<int, int>> q;
  pair<int, int> cur;
  int cnt = 0;
  int nx, ny;
  int dx[4] = {-1, 0, 1, 0};
  int dy[4] = {0, 1, 0, -1};

  q.push({r, c});
  while (!q.empty())
  {
    bool flag = false;
    cur = q.front();
    q.pop();
    if (board[cur.first][cur.second] == 0)
    {
      board[cur.first][cur.second] = 2;
      cnt++;
    }
    for (int i = 0; i < 4; i++)
    {
      nx = cur.first + dx[i];
      ny = cur.second + dy[i];
      if (board[nx][ny] == 1 || board[nx][ny] == 2) continue;
      flag = true;
      dir = dir == 0 ? 3 : dir - 1;
      break;
    }
    if (flag)
    {
      nx = cur.first + dx[dir];
      ny = cur.second + dy[dir];
      if (board[nx][ny] == 1 || board[nx][ny] == 2)
        q.push({cur.first, cur.second});
      else
        q.push({nx, ny});
    }
    else
    {
      int temp = dir > 1 ? dir - 2 : dir + 2;
      nx = cur.first + dx[temp];
      ny = cur.second + dy[temp];
      if (board[nx][ny] == 1)
        break;
      q.push({nx, ny});
    }
  }

  cout << cnt;

  return 0;
}