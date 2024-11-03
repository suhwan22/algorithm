#include <iostream>
#include <queue>
#include <map>

using namespace std;

class PPair
{
  public:
    int x;
    int y;
    bool crash;
    int step;
  public:
    PPair() {}
    PPair(int a, int b, bool k)
    {
      x = a;
      y = b;
      crash = k;
      step = 1;
    } 
    PPair(int a, int b, bool k, int s)
    {
      x = a;
      y = b;
      crash = k;
      step = s;
    } 
    void set(int a, int b, bool k)
    {
      x = a;
      y = b;
      crash = k;
    }
};

int board[1001][1001];
bool v[1001][1001] = {};

void printBoard(int n, int m)
{
  for (int i = 0 ; i < n + 2; i ++)
    cout << "-";
  cout << "\n";
  for (int i = 1; i <= n; i++)
  {
    cout << "|";
    for (int j = 1; j <= m; j++)
    {
      if (board[i][j] >= 0)
        cout << board[i][j];
      else
        cout << "#";
    }
    cout << "|\n";
  }
  for (int i = 0 ; i < n + 2; i ++)
    cout << "-";
  cout << "\n";
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int dx[4] = {0, -1, 0, 1};
  int dy[4] = {1, 0, -1, 0};
  int nx, ny;

  queue<PPair> q;
  PPair cur;
  
  int n, m;
  string input;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    cin >> input;
    // cout << "input: " << input << "\n";
    for (int j = 0; j < m; j++)
    {
      if (input.at(j) == '1')
        board[i + 1][j + 1] = -1;
      else
        board[i + 1][j + 1] = 0;
    }
  }
  // printBoard(n, m);

  q.push(PPair(1, 1, false));
  board[1][1] = 1;
  v[1][1] = true;
  int cnx, cny;
  while (!q.empty())
  {
    cur = q.front();
    q.pop();
    if (cur.x == n && cur.y == m)
      continue;
    for (int i = 0; i < 4; i++)
    {
      nx = cur.x + dx[i];
      ny = cur.y + dy[i];
      // cout << "nx: " << nx << ", ny: " << ny << "\n";
      if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
      if (cur.crash == true)
      {
        if (board[nx][ny] < 0 || (board[nx][ny] != 0 && board[nx][ny] <= cur.step + 1)) continue;
        board[nx][ny] = cur.step + 1;
        q.push(PPair(nx, ny, true, cur.step + 1));
      }
      else if (cur.crash == false)
      {
        // cout << "nx: " << nx << ", ny: " << ny << "\n";
        if (board[nx][ny] < 0)
        {
          // 벽뚫기 부분
          for (int j = 0; j < 4; j++)
          {
            // cout << "i: " << i << ", j: " << j << "\n";
            if ((i > 1) ? (i - 2 != j) : (j != i + 2))
            // 이미 왔던 곳으로 되돌아 가는 것을 막기위한 if 문
            {
              cnx = nx + dx[j];
              cny = ny + dy[j];
              // cout << "cnx: " << cnx << ", cny: " << cny << "\n";
              if (cnx < 1 || cny < 1 || cnx > n || cny > m)
                continue;
              if (board[cnx][cny] < 0 || (board[cnx][cny] != 0 && board[cnx][cny] <= cur.step + 2))
                continue;
              board[cnx][cny] = cur.step + 2;
              q.push(PPair(cnx, cny, true, cur.step + 2));
            }
          }
        }
        else
        {
          if (v[nx][ny]) continue;
          if (board[nx][ny] == 0 || board[nx][ny] > cur.step + 1)
            board[nx][ny] = cur.step + 1;
          v[nx][ny] = true;
          q.push(PPair(nx, ny, false, cur.step + 1));
        }
      }
    }
    // printBoard(n, m);
  }

  if (board[n][m] == 0)
    cout << -1;
  else
    cout << board[n][m];

  return 0;
}