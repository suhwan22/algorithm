#include <iostream>
#include <queue>
#include <map>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> m >> n;
  int board[1000][1000];
  bool v[1000][1000] = {};
  int dx[4] = {0, -1, 0, 1};
  int dy[4] = {1, 0, -1, 0};

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
      cin >> board[i][j];
  }

  queue<pair<int ,int>> q;
  pair<int, int> cur;
  int nx, ny;

  for (int x = 0; x < n; x++)
  {
    for (int y = 0; y < m; y++)
    {
      if (board[x][y] == 1)
      {
        v[x][y] = true;
        q.push({x, y});
      }
    }
  }

  while (!q.empty())
  {
    cur = q.front();
    q.pop();
    for (int i = 0; i < 4; i++)
    {
      nx = cur.first + dx[i];
      ny = cur.second + dy[i];
      if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
      if (v[nx][ny] == true || board[nx][ny] < 0) continue;
      v[nx][ny] = true;
      board[nx][ny] = board[cur.first][cur.second] + 1;
      q.push({nx, ny});
    }
  }

  int max = 0;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (board[i][j] == 0)
      {
        cout << -1;
        return 0;
      }
      else if (max < board[i][j])
        max = board[i][j];
    }
  }

  cout << max - 1;


  return 0;
}