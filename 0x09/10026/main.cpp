#include <iostream>
#include <queue>
#include <map>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  queue<pair<int, int>> q;
  pair<int, int> cur;
  int dx[4] = {0, -1, 0, 1};
  int dy[4] = {1, 0, -1, 0};
  int board[100][100] = {};
  bool v[100][100] = {};
  int nx, ny;
  int n;
  int cnt = 0;
  cnt = 0;
  cin >> n;

  string input;

  for (int i = 0; i < n; i++)
  {
    cin >> input;
    for (int j = 0; j < n; j++)
    {
      if (input.at(j) == 'R')
        board[i][j] = 1;
      else if (input.at(j) == 'G')
        board[i][j] = 2;
      else if (input.at(j) == 'B')
        board[i][j] = 3;
    }
  }

  for (int x = 0; x < n; x++)
  {
    for (int y = 0; y < n; y++)
    {
      if (v[x][y] == false)
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
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (v[nx][ny] || board[nx][ny] != board[cur.first][cur.second]) continue;
            v[nx][ny] = true;
            q.push({nx, ny});
          }
        }
      }
    }
  }

  cout << cnt << " ";
  cnt = 0;

  // 1 2 를 같게 봄
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (board[i][j] == 2)
        board[i][j] = 1;
      v[i][j] = false;
    }
  }

  for (int x = 0; x < n; x++)
  {
    for (int y = 0; y < n; y++)
    {
      if (v[x][y] == false)
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
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (v[nx][ny] || board[nx][ny] != board[cur.first][cur.second]) continue;
            v[nx][ny] = true;
            q.push({nx, ny});
          }
        }
      }
    }
  }
  cout << cnt;

  return 0;
}