#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int board[300][300];

void printBoard(int n, int m);

vector<pair<int, int>> vec[5];

// 1 <= 빙산 높이 <= 10
// 0 은 바다

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
      cin >> board[i][j];
  }


  int nx, ny;
  int dx[4] = {-1, 0 , 1, 0};
  int dy[4] = {0, 1, 0, -1};
  bool visit[300][300] = {};
  int cnt;
  int ice;
  int year = 0;
  while (1)
  {
    ice = 0;
    queue<pair<int, int>> q;
    pair<int, int> cur;
    bzero(visit, sizeof(visit));
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (visit[i][j] == false && board[i][j] > 0)
        {
          q.push({i, j});
          visit[i][j] = true;
          ice++;
          while (!q.empty())
          {
            cur = q.front();
            q.pop();
            cnt = 0;
            for (int i = 0; i < 4; i++)
            {
              nx = cur.first + dx[i];
              ny = cur.second + dy[i];
              if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
              if (visit[nx][ny]) continue;
              if (board[nx][ny] <= 0)
              {
                cnt++;
                continue;
              }
              visit[nx][ny] = true;
              q.push({nx, ny});
            }
            vec[cnt].push_back({cur.first, cur.second});
          }
        }
      }
    }
    if (ice >= 2 || ice == 0)
    {
      if (ice == 0)
        cout << 0;
      else
        cout << year;
      break;
    }
    for (int i = 1; i < 5; i++)
    {
      while (!vec[i].empty())
      {
        cur = vec[i].back();
        vec[i].pop_back();
        board[cur.first][cur.second] -= i;
      }
    }
    year++;
  }

  return 0;
}

void printBoard(int n, int m)
{
  cout << "--------------------\n";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << board[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "--------------------\n";
}