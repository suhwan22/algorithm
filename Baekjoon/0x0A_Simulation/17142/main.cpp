#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
// 5 <= n <= 50 : 연구소 크기
// 1 <= m <= 10 : 바이러스 개수
int board[50][50] = {};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  vector<pair<int, int>> virus;
  vector<int> seq;
  int input;
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> input;
      if (input == 1)
        board[i][j] = -1;
      else if (input == 2)
      {
        virus.push_back({i, j});
        seq.push_back(1);
        board[i][j] = -2;
      }
      else
      {
        board[i][j] = 0;
        cnt++;
      }
    }
  }
  if (cnt == 0)
  {
    cout << 0;
    return 0;
  }
  sort(virus.begin(), virus.end());
  int min = -1;
  for (int i = 0; i < m; i++)
    seq[i] = 0;
  do
  {
    queue<pair<int, int>> q;
    bool visit[50][50] = {};
    int set = 0;
    for (int i = 0; i < (int)seq.size(); i++)
    {
      if (seq[i] == 0)
      {
        q.push(virus[i]);
        visit[virus[i].first][virus[i].second] = true;
      }
    }
    pair<int, int> cur;
    int nx, ny;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int dep = 0;
    q.push({-1, -1});

    while (!q.empty())
    {
      cur = q.front();
      q.pop();
      if (cnt <= set)
      {
        dep++;
        break;
      }
      if (cur.first < 0)
      {
        if (q.empty())
          break;
        dep++;
        q.push({-1, -1});
        continue;
      }
      for (int i = 0; i < 4; i++)
      {
        nx = cur.first + dx[i];
        ny = cur.second + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if (visit[nx][ny] || board[nx][ny] == -1) continue;
        visit[nx][ny] = true;
        if (board[nx][ny] == -2)
        {
          int nx2, ny2;
          bool flag = false;
          for (int j = 0; j < 4; j++)
          {
            nx2 = nx + dx[j];
            ny2 = ny + dy[j];
            if (nx2 < 0 || ny2 < 0 || nx2 >= n || ny2 >= n) continue;
            if (visit[nx2][ny2] || board[nx2][ny2] == -1) continue;
            flag = true;
          }
          if (flag)
            q.push({nx, ny});
        }
        else
        {
          q.push({nx, ny});
          set++;
        }
      }
    }
    if (set >= cnt && (min == -1 || min > dep))
      min = dep;
  } while (next_permutation(seq.begin(), seq.end()));

  cout << min;

  return 0;
}