#include <iostream>
#include <queue>
#include <map>

using namespace std;

void printBoard(int board[1000][1000], int n, int m)
{
  cout << "------------------------------------------------\n";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (board[i][j] == -1)
        cout << "#";
      else if (board[i][j] == -2)
        cout << "F";
      else if (board[i][j] == 0)
        cout << ".";
      else
        cout << board[i][j];
    }
    cout << "\n";
  }
  cout << "------------------------------------------------\n";
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int board[1000][1000];
  bool v[1000][1000] = {};
  int n, m;
  int dx[4] = {0, -1, 0, 1};
  int dy[4] = {1, 0, -1, 0};
  cin >> n >> m;
  string input;
  for (int i = 0; i < n; i++)
  {
    cin >> input;
    for (int j = 0; j < m; j++)
    {
      if (input.at(j) == '#')
        board[i][j] = -1;
      else if (input.at(j) == '.')
        board[i][j] = 0;
      else if (input.at(j) == 'F')
        board[i][j] = -2;
      else if (input.at(j) == 'J')
        board[i][j] = 1;
    }
  }

  queue<pair<int, int>> q;
  pair<int, int> cur;
  pair<int, int> J;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (board[i][j] == -2)
      {
        v[i][j] = true;
        q.push({i, j});
      }
      else if (board[i][j] == 1)
        J = {i, j};
    }
  }
  v[J.first][J.second] = true;
  if (J.first == 0 || J.first == n - 1 || J.second == 0 || J.second == m - 1)
  {
    cout << 1;
    return 0;
  }
  q.push(J);

  int nx, ny;

  while (!q.empty())
  {
    cur = q.front();
    q.pop();
    for (int i = 0; i < 4; i++)
    {
      nx = cur.first + dx[i];
      ny = cur.second + dy[i];
      if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
      if (v[nx][ny] || board[nx][ny] == -1) continue;
      v[nx][ny] = true;
      if (board[cur.first][cur.second] == -2)
      {
        board[nx][ny] = -2;
        q.push({nx, ny});
      }
      else if (board[cur.first][cur.second] > 0
              && board[nx][ny] == 0)
      {
        board[nx][ny] = board[cur.first][cur.second] + 1;
        if (nx == n - 1 || ny == m - 1 || nx == 0 || ny == 0)
        {
          // printBoard(board, n, m);
          cout << board[nx][ny];
          return 0;
        }
        q.push({nx, ny});
      }
    }
  }
  cout << "IMPOSSIBLE";

  return 0;
}