#include <iostream>
#include <queue>

using namespace std;

struct PPair
{
  int x;
  int y;
  int step;
  int en;
  bool day;
};

int board[1000][1000] = {};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k;
  cin >> n >> m >> k;
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

  queue<PPair> q;
  PPair cur;
  bool visit[2][11][1000][1000] = {};
  // bool visit[2][11][100][100] = {};
  // 필요한 stack memory 가 너무 커서 stack-overflow 또는 segmentation fault 가 발생할 수 있다.
  // -Wl,-stack_size,0x20000000 옵션을 주면 512MB 만큼의 stack_size 를 선택할 수 있다.
  // 백준이 보통 512MB 가 기준이라 그런거지 원하는 만큼 줘도 됨

  cur.x = 0;
  cur.y = 0;
  cur.step = 1;
  cur.en = k;
  cur.day = true;
  q.push({cur});
  visit[1][k][0][0] = true;

  int dx[4] = {-1, 0, 1, 0};
  int dy[4] = {0, 1, 0, -1};
  int nx, ny;
  PPair temp;

  while (!q.empty())
  {
    cur = q.front();
    q.pop();
    for (int i = 0; i < 4; i++)
    {
      nx = cur.x + dx[i];
      ny = cur.y + dy[i];
      if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
      if (board[nx][ny] == -1)
      {
        if (cur.en == 0) continue;
        if (cur.day)
        {
          if (visit[!cur.day][cur.en - 1][nx][ny]) continue;
          visit[!cur.day][cur.en - 1][nx][ny] = true;
          if (board[nx][ny] == 0 || board[nx][ny] > cur.step + 1)
            board[nx][ny] = cur.step + 1;
          temp.day = !cur.day;
          temp.en = cur.en - 1;
          temp.step = cur.step + 1;
          temp.x = nx;
          temp.y = ny;
          q.push(temp);
        }
        else
        {
          if (visit[!cur.day][cur.en][cur.x][cur.y]) continue;
          visit[!cur.day][cur.en][cur.x][cur.y] = true;
          temp.day = !cur.day;
          temp.en = cur.en;
          temp.step = cur.step + 1;
          temp.x = cur.x;
          temp.y = cur.y;
          q.push(temp);
        }
      }
      else
      {
        if (visit[!cur.day][cur.en][nx][ny]) continue;
        visit[!cur.day][cur.en][nx][ny] = true;
        if (board[nx][ny] == 0 || board[nx][ny] > cur.step + 1)
          board[nx][ny] = cur.step + 1;
        temp.day = !cur.day;
        temp.en = cur.en;
        temp.step = cur.step + 1;
        temp.x = nx;
        temp.y = ny;
        q.push(temp);
      }
    }
  }

  cout << (board[n-1][m-1] == 0 ? -1 : board[n-1][m-1]);

  return 0;
}