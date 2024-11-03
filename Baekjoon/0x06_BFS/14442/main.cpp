#include <iostream>
#include <queue>

using namespace std;

int board[1000][1000] = {};
bool visit[11][1000][1000] = {};
int n, m, k;

class Pos
{
  public:
    int x;
    int y;
    int en;
    int step;

    Pos() {};
    Pos(int _x, int _y, int _en) : x(_x), y(_y), en(_en) {step = 1;}
    Pos(int _x, int _y, int _en, int _step) : x(_x), y(_y), en(_en), step(_step) {}
};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;
  // 1 <= n, m <= 1,000
  // 1 <= k <= 10

  string input;
  for (int i = 0; i < n; i++)
  {
    cin >> input;
    for (int j = 0; j < m; j++)
    {
      if (input[j] == '0')
        board[i][j] = 0;
      else
        board[i][j] = -1;
    }
  }

  if (n == 1 && m == 1)
  {
    cout << 1;
    return 0;
  }

  queue<Pos> q;
  Pos cur;
  q.push(Pos(0, 0, k));
  ::visit[k][0][0] = true;

  int dx[4] = {-1, 0, 1, 0};
  int dy[4] = {0, 1, 0, -1};
  int nx, ny;

  while (!q.empty())
  {
    cur = q.front();
    // cout << "cur x: " << cur.x << ", y: " << cur.y << "cur.step: " << cur.step << "\n";
    q.pop();
    for (int i = 0; i < 4; i++)
    {
      nx = cur.x + dx[i];
      ny = cur.y + dy[i];
      if (nx == n - 1 && ny == m - 1)
      {
        if (board[nx][ny] == 0 || board[nx][ny] > cur.step + 1)
          board[nx][ny] = cur.step + 1;
        continue;
      }
      if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
      if (cur.en > 0)
      // 아직 벽을 뚫을 수 있는 경우
      {
        if (board[nx][ny] == -1)
        // 벽을 부수고 가는 경우
        {
          if (::visit[cur.en - 1][nx][ny]) continue;
          ::visit[cur.en - 1][nx][ny] = true;
          q.push(Pos(nx, ny, cur.en - 1, cur.step + 1));
        }
        else
        {
          if (::visit[cur.en][nx][ny]) continue;
          ::visit[cur.en][nx][ny] = true;
          if (board[nx][ny] == 0 || board[nx][ny] > cur.step + 1)
            board[nx][ny] = cur.step + 1;
          q.push(Pos(nx, ny, cur.en, cur.step + 1));
        }
      }
      else
      // 더 이상 벽을 뚫을 수 없는 경우
      {
        if (board[nx][ny] == -1 || ::visit[cur.en][nx][ny]) continue;
        ::visit[cur.en][nx][ny] = true;
        if (board[nx][ny] == 0 || board[nx][ny] > cur.step + 1)
          board[nx][ny] = cur.step + 1;
        q.push(Pos(nx, ny, cur.en, cur.step + 1));
      }
    }
  }

  cout << (board[n-1][m-1] != 0 ? board[n-1][m-1] : -1);

  return 0;
}