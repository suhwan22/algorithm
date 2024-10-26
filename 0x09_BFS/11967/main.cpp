#include <iostream>
#include <queue>

// -Wl,-stack_size,0x20000000 옵션 필요함

using namespace std;

bool board[101][101] = {};
vector<pair<int, int>> input[101][101] = {};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  bool visit[10001][101][101] = {};

  int n, m;
  cin >> n >> m;
  int x1, y1, x2, y2;
  for (int i = 0; i < m; i++)
  {
    cin >> x1 >> y1 >> x2 >> y2;
    input[x1][y1].push_back({x2, y2});
  }
  queue<pair<int, int>> q;
  pair<int, int> cur;
  visit[1][1][1] = true;
  board[1][1] = true;
  q.push({1, 1});
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  int nx, ny;

  int cnt = 1;
  pair<int, int> temp;
  while (!q.empty())
  {
    cur = q.front();
    q.pop();
    for (int i = 0; i < (int)input[cur.first][cur.second].size(); i++)
    {
      temp = input[cur.first][cur.second][i];
      if (board[temp.first][temp.second]) continue;
      board[temp.first][temp.second] = true;
      cnt++;
    }
    for (int i = 0; i < 4; i++)
    {
      nx = cur.first + dx[i];
      ny = cur.second + dy[i];
      if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
      if (board[nx][ny] == false || visit[cnt][nx][ny]) continue;
      visit[cnt][nx][ny] = true;
      q.push({nx, ny});
    }
  }
  cout << cnt;

  return 0;
}