#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int board[25][25] = {};
  bool v[25][25] = {};

  int n;
  cin >> n;
  string input;
  for (int i = 0; i < n; i++)
  { 
    cin >> input;
    for (int j = 0; j < n; j++)
    {
      if (input.at(j) == '0')
        board[i][j] = 0;
      else if (input.at(j) == '1')
        board[i][j] = 1;
      else
      {
        cout << "input error\n";
        return 1;
      }
    }
  }

  queue<pair<int, int>> q;
  pair<int, int> cur;
  int dx[4] = {0, -1, 0, 1};
  int dy[4] = {1, 0, -1, 0};
  int nx, ny;
  int size;
  vector<int> ans;
  for (int x = 0; x < n; x++)
  {
    for (int y = 0; y < n; y++)
    {
      if (board[x][y] && !v[x][y])
      {
        v[x][y] = true;
        q.push({x, y});
        size = 1;
        while (!q.empty())
        {
          cur = q.front();
          q.pop();
          for (int i = 0; i < 4; i++)
          {
            nx = cur.first + dx[i];
            ny = cur.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (v[nx][ny] || board[nx][ny] == 0) continue;
            v[nx][ny] = true;
            size++;
            q.push({nx, ny});
          }
        }
        ans.push_back(size);
      }
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << "\n";
  for (int i = 0; i < (int)ans.size(); i++)
  {
    cout << ans[i] << "\n";
  }

  return 0;
}