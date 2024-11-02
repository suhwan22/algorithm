#include <iostream>
#include <queue>
#include <map>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int board[100][100];
  bool v[100][100] = {};
  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};

  int n, m;
  cin >> n >> m;

  string input;
  for (int i = 0; i < n; i++)
  {
    cin >> input;
    for (int j = 0; j < m; j++)
      board[i][j] = input[j] - '0';
  }

  int nx, ny;

  queue<pair<int, int>> q;
  pair<int, int> cur;
  v[0][0] = true;
  q.push({0, 0});
  while (!q.empty())
  {
    cur = q.front();
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
      board[nx][ny] += board[cur.first][cur.second];
      v[nx][ny] = true;
      q.push({nx, ny});
    }
  }
  cout << board[n - 1][m - 1];

  return 0;
}