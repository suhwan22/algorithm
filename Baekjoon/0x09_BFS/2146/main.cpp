#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int board[100][100] = {};
int island[101] = {};

void printBoard(int n);

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cin >> board[i][j];
  }

  pair<int ,int> cur;
  queue<pair<int, int>> q;
  bool v[100][100] = {};

  int dx[4] = {-1, 0, 1, 0};
  int dy[4] = {0, 1, 0, -1};
  int nx, ny;
  int cnt = 0;

  for (int x = 0; x < n; x++)
  {
    for (int y = 0; y < n; y++)
    {
      if (v[x][y] == false && board[x][y] != 0)
      {
        cnt++;
        v[x][y] = true;
        q.push({x, y});
        while (!q.empty())
        {
          cur = q.front();
          board[cur.first][cur.second] = cnt;
          q.pop();
          for (int i = 0; i < 4; i++)
          {
            nx = cur.first + dx[i];
            ny = cur.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (v[nx][ny] || board[nx][ny] == 0) continue;
            v[nx][ny] = true;
            q.push({nx, ny});
          }
        }
      }
    }
  }
  printBoard(n);
  bool flag = false;
  int min = 2147483647;

  while (1)
  {
    bzero(v, sizeof(v));
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (v[i][j] == false && board[i][j] != 0)
        {
          v[i][j] = true;
          q.push({i, j});
          while (!q.empty())
          {
            cur = q.front();
            q.pop();
            for (int k = 0; k < 4; k++)
            {
              nx = cur.first + dx[k];
              ny = cur.second + dy[k];
              if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;
              if (board[nx][ny] != 0 && board[nx][ny] != board[cur.first][cur.second])
              {
                flag = true;
                if (min > island[board[nx][ny]] + island[board[cur.first][cur.second]])
                  min = island[board[nx][ny]] + island[board[cur.first][cur.second]];
              }
              if (v[nx][ny])
                continue;
              v[nx][ny] = true;
              if (board[nx][ny] == 0)
                board[nx][ny] = board[cur.first][cur.second];
              else
                q.push({nx, ny});
            }
          }
          island[board[i][j]]++;
        }
      }
    }
    if (flag)
    {
      cout << min;
      return 0;
    }
  printBoard(n);
  }

  return 0;
}

void printBoard(int n)
{
  cout << "---------------------\n";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cout << board[i][j] << " ";
    cout << "\n";
  }
  cout << "---------------------\n";
}

/*

7
1 0 0 0 0 0 1
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 1 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
1 0 0 0 0 1 1


*/