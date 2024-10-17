#include <iostream>
#include <queue>

using namespace std;

int board[200][200] = {};


typedef struct Monkey
{
  int x;
  int y;
  int available;
  int step;
} Monkey;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int k, n, m;
  cin >> k >> m >> n;

  // 0 <= k <= 30 : 원숭이가 말처럼 이동할 수 있는 횟수
  // 1 <= n,m <= 200 : n x m 의 보드
  // 0: 평지, 1: 장애물
  // 장애물에는 가지 못함
  // (0,0) -> (n-1, m-1) 까지 가는 최소 횟수, 갈 수 없으면 -1 출력

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
      cin >> board[i][j];
  }
  if (m == 1 && n == 1)
  {
    cout << 0;
    return 0;
  }

  queue<Monkey> q;
  Monkey temp;
  temp.x = 0;
  temp.y = 0;
  temp.available = k;
  temp.step = 0;
  q.push(temp);
  Monkey cur;

  int nx, ny;
  int dx[4] = {-1, 0, 1, 0};
  int dy[4] = {0, 1, 0, -1};

  int hdx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
  int hdy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

  bool visit[31][200][200] = {};
  visit[k][0][0] = true;
  int min = 2147483647;

  while (!q.empty())
  {
    cur = q.front();
    q.pop();
    for (int i = 0; i < 4; i++)
    {
      nx = cur.x + dx[i];
      ny = cur.y + dy[i];
      if (nx == n-1 && ny == m-1 && cur.step + 1 < min)
      {
        min = cur.step + 1;
        break;
      }
      if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
      if (visit[cur.available][nx][ny] || board[nx][ny] == 1) continue;
      visit[cur.available][nx][ny] = true;
      temp.available = cur.available;
      temp.step = cur.step + 1;
      temp.x = nx;
      temp.y = ny;
      q.push(temp);
    }
    if (cur.available != 0)
    {
      for (int i = 0; i < 8; i++)
      {
        nx = cur.x + hdx[i];
        ny = cur.y + hdy[i];
        if (nx == n - 1 && ny == m - 1 && cur.step + 1 < min)
        {
          min = cur.step + 1;
          break;
        }
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (visit[cur.available - 1][nx][ny] || board[nx][ny] == 1) continue;
        visit[cur.available - 1][nx][ny] = true;
        temp.available = cur.available - 1;
        temp.step = cur.step + 1;
        temp.x = nx;
        temp.y = ny;
        q.push(temp);
      }
    }
  }

  cout << (min != 2147483647 ? min : -1);

  return 0;
}