#include <iostream>
#include <queue>

using namespace std;

/*
3
5 17
*****************
.............**$*
*B*A*P*C**X*Y*.X.
*y*x*a*p**$*$**$*
*****************
cz
*/

int board[100][100] = {};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, n, m;
  string input;
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  int nx, ny;

  cin >> t;
  int cnt;
  while (t--)
  {
    cnt = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
      cin >> input;
      for (int j = 0; j < m; j++)
      {
        if (input[j] == '*')
          board[i][j] = -1;
        else if (input[j] == '.')
          board[i][j] = 0;
        else if (input[j] == '$')
          board[i][j] = 1;
        else
          board[i][j] = input[j];
      }
    }
    bool key[26] = {};
    int kCnt = 0;
    cin >> input;
    for (char c : input)
    {
      if (c == '0')
        break;
      kCnt++;
      key[c - 'a'] = true;
    }
    bool visit[27][100][100] = {};
    queue<pair<int, int>> q;
    vector<pair<int, int>> start;
    pair<int, int> cur;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (i != 0 && i != n - 1 && j != 0 && j != m - 1)
          continue;
        if (board[i][j] == 0)
          start.push_back({i, j});
        else if (board[i][j] == 1)
        {
          board[i][j] = 0;
          cnt++;
          start.push_back({i, j});
        }
        else if (board[i][j] >= 'a' && board[i][j] <= 'z')
        {
          key[board[i][j] - 'a'] = true;
          board[i][j] = 0;
          start.push_back({i, j});
        }
        else if (board[i][j] >= 'A' && board[i][j] <= 'Z')
          start.push_back({i, j});
      }
    }
    for (pair<int, int> p : start)
    {
      if (board[p.first][p.second] >= 'A' && board[p.first][p.second] <= 'Z' && key[tolower(board[p.first][p.second]) - 'a'] == false)
        continue;
      q.push(p);
      visit[kCnt][p.first][p.second] = true;
    }
    while (!q.empty())
    {
      cur = q.front();
      cout << "cur: " << cur.first << ", " << cur.second << "\n";
      q.pop();
      for (int i = 0; i < 4; i++)
      {
        nx = cur.first + dx[i];
        ny = cur.second + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (board[nx][ny] >= 'A' && board[nx][ny] <= 'Z' && key[tolower(board[nx][ny]) - 'a'] == false) continue;
        if (visit[kCnt][nx][ny] || board[nx][ny] == -1) continue;
        visit[kCnt][nx][ny] = true;
        if (board[nx][ny] >= 'a' && board[nx][ny] <= 'z' && key[board[nx][ny] - 'a'] == false)
        {
          cout << (char)board[nx][ny] << " key get\n";
          key[board[nx][ny] - 'a'] = true;
          kCnt++;
          for (pair<int, int> p : start)
          {
            if (board[p.first][p.second] >= 'A' && board[p.first][p.second] <= 'Z' && key[tolower(board[p.first][p.second]) - 'a'] == false)
              continue;
            q.push(p);
            visit[kCnt][p.first][p.second] = true;
          }
        }
        if (board[nx][ny] == 1)
        {
          // cout << "$ get\n";
          board[nx][ny] = 0;
          cnt++;
        }
        q.push({nx, ny});
      }
    }
    cout << cnt << "\n";
  }

  return 0;
}