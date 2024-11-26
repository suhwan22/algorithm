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
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> board[i][j];
      if (board[i][j] == 2)
      {
        virus.push_back({i, j});
        seq.push_back(1);
        board[i][j] = 0;
      }
    }
  }
  sort(virus.begin(), virus.end());
  int min = -1;
  for (int i = 0; i < m; i++)
    seq[i] = 0;
  do
  {
    queue<pair<int, int>> q;
    bool visit[50][50] = {};
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
        if (visit[nx][ny] || board[nx][ny] == 1) continue;
        visit[nx][ny] = true;
        q.push({nx, ny});
      }
    }
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
        if (board[i][j] != 1 && visit[i][j] == false)
          flag = false;
    }
    if (flag && (min == -1 || min > dep))
      min = dep;
  } while (next_permutation(seq.begin(), seq.end()));

  cout << min;

  return 0;
}