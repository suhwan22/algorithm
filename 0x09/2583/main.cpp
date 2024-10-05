#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

void printBoard(int board[100][100], int n, int m)
{
  cout << "----------------------------------\n";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << board[i][j];
    }
    cout << "\n";
  }
  cout << "----------------------------------\n";
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int board[100][100] = {};
  bool v[100][100] = {};

  int n, m, k;
  cin >> m >> n >> k;
  // n 행, m 열의 크기, k 직사각형의 개수 당 2개의 좌표 들어올 예정,왼쪽 아래 좌표 오른쪽 위 좌표

  int x1, x2, y1, y2;
  while (k--)
  {
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = x1; i < x2; i++)
    {
      for (int j = y1; j < y2; j++)
        board[i][j] = 1;
    }
  }
  // printBoard(board, n, m);

  queue<pair<int, int>> q;
  pair<int, int> cur;
  int dx[4] = {0, -1, 0, 1};
  int dy[4] = {1, 0, -1, 0};
  int cnt = 0;
  int size = 0;
  vector<int> ans;

  for (int x = 0; x < n; x++)
  {
    for (int y = 0; y < m; y++)
    {
      if (board[x][y] == 0 && !v[x][y])
      {
        size = 1;
        cnt++;
        v[x][y] = true;
        q.push({x, y});
        while (!q.empty())
        {
          cur = q.front();
          q.pop();
          for (int i = 0; i < 4; i++)
          {
            x1 = cur.first + dx[i];
            y1 = cur.second + dy[i];
            if (x1 < 0 || y1 < 0 || x1 >= n || y1 >= m) continue;
            if (v[x1][y1] || board[x1][y1]) continue;
            v[x1][y1] = true;
            size++;
            q.push({x1, y1});
          }
        }
        ans.push_back(size);
      }
    }
  }

  sort(ans.begin(), ans.end());
  cout << cnt << "\n";
  for (int i = 0; i < (int)ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  return 0;
}