#include <iostream>
#include <map>
#include <queue>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int board[500][500];
  bool v[500][500] = {};
  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};
  queue<pair<int, int>> q;

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> board[i][j];
    }
  }

  int nx, ny;
  int cnt = 0;
  int max = 0;
  int size = 0;
  for (int x = 0; x < n; x++)
  {
    for (int y = 0; y < m; y++)
    {
      if (v[x][y] != true && board[x][y] == 1)
      {
        v[x][y] = true;
        q.push({x, y});
        cnt++;
        size = 1;
        while (!q.empty())
        {
          pair<int, int> cur = q.front();
          q.pop();
          // cout << "cur (" << cur.first << ", " << cur.second << ")\n";
          for (int i = 0; i < 4; i++)
          {
            nx = cur.first + dx[i];
            ny = cur.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
              continue;
            if (v[nx][ny] == true || board[nx][ny] != 1)
              continue;
            size++;
            v[nx][ny] = true;
            q.push({nx, ny});
          }
        }
        if (size > max)
          max = size;
      }
    }
  }

  cout << cnt << "\n" << max;

  return 0;
}