#include <iostream>
#include <set>
#include <queue>

using namespace std;

int board[1000][1000] = {};
bool visited[1000][1000] = {};
int bfs[500001] = {};
int n, m;

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;

  string input;
  for (int i = 0; i < n; i++)
  {
    cin >> input;
    for (int j = 0; j < m; j++)
    {
      if (input[j] == '0')
        board[i][j] = input[j] - '0';
      else
        board[i][j] = -1;
    }
  }

  queue<pair<int, int>> q;
  pair<int, int> cur;
  int nx, ny;
  int dx[4] = {0, -1, 0, 1};
  int dy[4] = {1, 0, -1, 0};

  int idx = 1;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (board[i][j] == 0)
      {
        vector<pair<int, int>> arr;
        visited[i][j] = true;
        q.push({i, j});
        arr.push_back({i, j});
        while (!q.empty())
        {
          cur = q.front();
          q.pop();
          for (int k = 0; k < 4; k++)
          {
            nx = cur.first + dx[k];
            ny = cur.second + dy[k];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (visited[nx][ny] || board[nx][ny] == -1) continue;
            visited[nx][ny] = true;
            arr.push_back({nx, ny});
            q.push({nx, ny});
          }
        }
        bfs[idx] = arr.size();
        for (auto p : arr)
          board[p.first][p.second] = idx;
        idx++;
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (board[i][j] == -1)
      {
        set<int> s;
        int sum = 1;
        for (int k = 0; k < 4; k++)
        {
          nx = i + dx[k];
          ny = j + dy[k];
          if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
          if (board[nx][ny] < 0) continue;
          s.insert(board[nx][ny]);
        }
        for (int a : s)
          sum += bfs[a];
        board[i][j] = -sum;
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (board[i][j] < 0)
        cout << -(board[i][j] % 10);
      else
        cout << 0;
    }
    cout << "\n";
  }
  
  return 0;
}