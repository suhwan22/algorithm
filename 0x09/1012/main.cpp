#include <iostream>
#include <queue>
#include <map>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  queue<pair<int, int>> q;
  pair <int, int> cur;
  int dx[4] = {0, -1, 0, 1};
  int dy[4] = {1, 0, -1, 0};
  int board[50][50] = {};
  bool v[50][50] = {};
  int nx, ny;
  int n, m, k;
  int t;
  int cnt = 0;
  cin >> t;
  while (t--)
  {
    cnt = 0;
    cin >> m >> n >> k;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        board[i][j] = 0;
        v[i][j] = 0;
      }
    }
    while (k--)
    {
      cin >> ny >> nx;
      board[nx][ny] = 1;
    }
    for (int x = 0; x < n; x++)
    {
      for (int y = 0 ; y < m; y++)
      {
        if (v[x][y] == false && board[x][y] == 1)
        {
          cnt++;
          v[x][y] = true;
          q.push({x, y});
          while (!q.empty())
          {
            cur = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
              nx = cur.first + dx[i];
              ny = cur.second + dy[i];
              if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
              if (v[nx][ny] || board[nx][ny] == 0) continue;
              v[nx][ny] = true;
              q.push({nx, ny});
            }
          }
        }
      }
    }
    cout << cnt << "\n";
  }



  return 0;
}