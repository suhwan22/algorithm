#include <iostream>

using namespace std;

int n, m, k;

struct Shark
{
  int speed;
  int size;
  int dir;
};

Shark board[102][101][101] = {};

void moveShark(int t, int x, int y);
void printBoard(int t);

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  int x, y;
  for (int i = 0; i < k; i++)
    cin >> x >> y >> board[1][x][y].speed >> board[1][x][y].dir >> board[1][x][y].size;
  int ans = 0;
  for (int t = 1; t <= m; t++)
  {
    printBoard(t);
    for (int i = 1; i <= n; i++)
    {
      if (board[t][i][t].size == 0) continue;
      ans += board[t][i][t].size;
      board[t][i][t].size = 0;
      break;
    }
    printBoard(t);
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= m; j++)
      {
        if (board[t][i][j].size > 0)
          moveShark(t, i, j);
      }
    }
  }

  cout << ans;

  return 0;
}


void moveShark(int t, int x, int y)
{
  int dir = board[t][x][y].dir;
  int nx, ny;
  if (dir == 1)
  {
    int cnt = board[t][x][y].speed % (2 * n - 2);
    ny = y;
    if (cnt <= x - 1)
      nx = x - cnt;
    else if (cnt <= n + x - 2)
    {
      nx = 1 + (cnt - (x - 1));
      board[t][x][y].dir = 2;
    }
    else
      nx = n - (cnt - (n + x - 2));
    if (board[t+1][nx][ny].size > board[t][x][y].size) return;
    board[t+1][nx][ny] = board[t][x][y];
  }
  else if (dir == 2)
  {
    int cnt = board[t][x][y].speed % (2 * n - 2);
    ny = y;
    if (cnt <= n - x)
      nx = x + cnt;
    else if (cnt <= 2 * n - x - 1)
    {
      nx = n - (cnt - (n - x));
      board[t][x][y].dir = 1;
    }
    else
      nx = 1 + (cnt - (2 * n - x - 1));
    if (board[t+1][nx][ny].size > board[t][x][y].size) return;
    board[t+1][nx][ny] = board[t][x][y];
  }
  else if (dir == 3)
  {
    int cnt = board[t][x][y].speed % (2 * m - 2);
    nx = x;
    if (cnt <= m - y)
      ny = y + cnt;
    else if (cnt <= 2 * m - y - 1)
    {
      ny = m - (cnt - (m - y));
      board[t][x][y].dir = 4;
    }
    else
      ny = 1 + (cnt - (2 * m - y - 1));
    if (board[t+1][nx][ny].size > board[t][x][y].size) return;
    board[t+1][nx][ny] = board[t][x][y];
  }
  else if (dir == 4)
  {
    int cnt = board[t][x][y].speed % (2 * m - 2);
    nx = x;
    if (cnt <= y - 1)
      ny = y - cnt;
    else if (cnt <= m + y - 2)
    {
      ny = 1 + (cnt - (y - 1));
      board[t][x][y].dir = 3;
    }
    else
      ny = m - (cnt - (m + y - 2));
    if (board[t+1][nx][ny].size > board[t][x][y].size) return;
    board[t+1][nx][ny] = board[t][x][y];
  }
}

void printBoard(int t)
{
  cout << "-----------------------\n";
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      cout << board[t][i][j].size << " ";
    }
    cout << "\n";
  }
  cout << "-----------------------\n";
}