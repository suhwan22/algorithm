#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  int board[100][100];
  bool v[100][100];
  vector<int> h;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> board[i][j];
      if (find(h.begin(), h.end(), board[i][j]) == h.end())
        h.push_back(board[i][j]);
    }
  }

  int dx[4] = {0, -1, 0, 1};
  int dy[4] = {1, 0, -1, 0};
  int nx, ny;
  queue<pair<int, int>> q;
  pair<int, int> cur;

  sort(h.begin(), h.end());
  int cnt;
  int max = 1;

  for (int i = 0; i < (int)h.size(); i++)
  {
    bzero(v, sizeof(v));
    cnt = 0;
    // cout << "current max: " << max << "\n";
    for (int x = 0; x < n; x++)
    {
      for (int y = 0; y < n; y++)
      {
        if (board[x][y] - h[i] > 0 && !v[x][y])
        {
          q.push({x, y});
          v[x][y] = true;
          cnt++;
          // cout << "cnt: " << cnt << "\n";
          while (!q.empty())
          {
            cur = q.front();
            q.pop();
            for (int j = 0; j < 4; j++)
            {
              nx = cur.first + dx[j];
              ny = cur.second + dy[j];
              if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
              if (v[nx][ny] || board[nx][ny] - h[i] <= 0) continue;
              v[nx][ny] = true;
              q.push({nx, ny});
            }
          }
        }
      }
    }
    if (max < cnt)
      max = cnt;
  }

  cout << max;

  return 0;
}