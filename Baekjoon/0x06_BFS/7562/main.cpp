#include <iostream>
#include <queue>
#include <map>

using namespace std;

void printBoard(int board[300][300], int n)
{
  cout << "--------------------------\n";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << board[i][j];
    }
    cout << "\n";
  }
  cout << "--------------------------\n";
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, t;
  cin >> t;
  int board[300][300];
  bool v[300][300] = {};
  int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
  int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};

  queue<pair<int ,int>> q;
  pair<int, int> cur;
  int nx, ny;
  int bx, by;

  while (t--)
  {
    cin >> n;
    m = n;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        board[i][j] = 0;
        v[i][j] = false;
      }
    }

    cin >> bx >> by;
    board[bx][by] = 1;
    cin >> nx >> ny;
    board[nx][ny] = -1;

    if (bx == nx && by == ny)
    {
      cout << 0 << "\n";
      continue;
    }

    v[bx][by] = true;
    q.push({bx, by});
    while (!q.empty())
    {
      cur = q.front();
      q.pop();
      for (int i = 0; i < 8; i++)
      {
        nx = cur.first + dx[i];
        ny = cur.second + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
          continue;
        if (v[nx][ny] == true || board[nx][ny] > 0)
          continue;
        v[nx][ny] = true;
        if (board[nx][ny] == -1)
        {
          cout << board[cur.first][cur.second] << "\n";
          while (!q.empty())
            q.pop();
          break;
        }
        board[nx][ny] = board[cur.first][cur.second] + 1;
        q.push({nx, ny});
        // printBoard(board, n);
      }
    }
  }

  return 0;
}