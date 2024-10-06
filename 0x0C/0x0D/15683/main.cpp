#include <iostream>
#include <map>
#include <queue>

using namespace std;

int board[8][8] = {};
queue<pair<int ,int>> q;
int min = 2147483647; // 이렇게 하면 cctv가 아에 없는 경우는 처리가 안되니 빈칸의 개수로 설정하면 좋음

// 그냥 전수조사 하면 되는 문제,, 근데 cctv 개수가 제한이 없으면 시간이 너무 올래 걸려서 다른 방식 있나 했는데
// 8개로 제한이 있네.. 그러면 깊어봤자 4^8승이라 ㅎ..

#define DIR_N 0
#define DIR_W 1
#define DIR_S 2
#define DIR_E 3

void setLine(int x, int y, int n, int m, int set, int dir);
void reLine(int x, int y, int n, int m, int set, int dir);
void func(int n, int m, int d);
int calBoard(int n, int m);
void printBoard(int n, int m);

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;

  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> board[i][j];
      if (board[i][j] != 0 && board[i][j] != 6)
        q.push({i, j});
    }
  }

  func(n, m, -1);
  cout << ::min;

  return 0;
}

void func(int n, int m, int d)
{
  if (d < -10)
    return;
  // printBoard(n, m);
  if (q.empty())
  {
    int cnt = calBoard(n, m);
    if (::min > cnt)
      ::min = cnt;
    return ;
  }
  pair<int ,int> cur = q.front();
  int type = board[cur.first][cur.second];
  q.pop();
  if (type == 1)
  {
    for (int i = 0; i < 4; i++)
    {
      setLine(cur.first, cur.second, n, m, d, i);
      func(n, m, d - 1);
      reLine(cur.first, cur.second, n, m, d, i);
    }
  }
  else if (type == 2)
  {
    for (int i = 0; i < 2; i++)
    {
      setLine(cur.first, cur.second, n, m, d, i);
      setLine(cur.first, cur.second, n, m, d, i + 2);
      func(n, m, d - 1);
      reLine(cur.first, cur.second, n, m, d, i);
      reLine(cur.first, cur.second, n, m, d, i + 2);
    }
  }
  else if (type == 3)
  {
    for (int i = 0; i < 4; i++)
    {
      setLine(cur.first, cur.second, n, m, d, i);
      setLine(cur.first, cur.second, n, m, d, i + 1 >= 4 ? i - 3 : i + 1);
      func(n, m, d - 1);
      reLine(cur.first, cur.second, n, m, d, i);
      reLine(cur.first, cur.second, n, m, d, i + 1 >= 4 ? i - 3 : i + 1);
    }
  }
  else if (type == 4)
  {
    for (int i = 0; i < 4; i++)
    {
      setLine(cur.first, cur.second, n, m, d, i);
      setLine(cur.first, cur.second, n, m, d, i + 1 >= 4 ? i - 3 : i + 1);
      setLine(cur.first, cur.second, n, m, d, i + 2 >= 4 ? i - 2 : i + 2);
      func(n, m, d - 1);
      reLine(cur.first, cur.second, n, m, d, i);
      reLine(cur.first, cur.second, n, m, d, i + 1 >= 4 ? i - 3 : i + 1);
      reLine(cur.first, cur.second, n, m, d, i + 2 >= 4 ? i - 2 : i + 2);
    }
  }
  else if (type == 5)
  {
    for (int i = 0; i < 4; i++)
      setLine(cur.first, cur.second, n, m, d, i);
    func(n, m, d - 1);
    for (int i = 0; i < 4; i++)
      reLine(cur.first, cur.second, n, m, d, i);
  }
  q.push({cur.first, cur.second});
}

void printBoard(int n, int m)
{
  cout << "-------------------------\n";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << board[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "-------------------------\n";
}

int calBoard(int n, int m)
{
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (board[i][j] == 0)
        cnt++;
    }
  }
  return cnt;
}

void setLine(int x, int y, int n, int m, int set, int dir)
{
  // cout << "[seLint] x: " << x << ", y: " << y << ", set: " << set << ", dir: " << dir << "\n";
  if (dir == 0)
  // N
  {
    for (int i = x - 1; i >= 0; i--)
    {
      if (board[i][y] == 6)
        break;
      if (board[i][y] == 0)
        board[i][y] = set;
    }
  }
  else if (dir == 1)
  // W
  {
    for (int j = y - 1; j >= 0; j--)
    {
      if (board[x][j] == 6)
        break;
      if (board[x][j] == 0)
        board[x][j] = set;
    }
  }
  else if (dir == 2)
  // S
  {
    for (int i = x + 1; i < n; i++)
    {
      if (board[i][y] == 6)
        break;
      if (board[i][y] == 0)
        board[i][y] = set;
    }
  }
  else if (dir == 3)
  // E
  {
    for (int j = y + 1; j < m; j++)
    {
      if (board[x][j] == 6)
        break;
      if (board[x][j] == 0)
        board[x][j] = set;
    }
  }
}

void reLine(int x, int y, int n, int m, int set, int dir)
{
  // cout << "[reLint] x: " << x << ", y: " << y << ", set: " << set << ", dir: " << dir << "\n";
  if (dir == 0)
  // N
  {
    for (int i = x - 1; i >= 0; i--)
    {
      if (board[i][y] == 6)
        break;
      if (board[i][y] == set)
        board[i][y] = 0;
    }
  }
  else if (dir == 1)
  // W
  {
    for (int j = y - 1; j >= 0; j--)
    {
      if (board[x][j] == 6)
        break;
      if (board[x][j] == set)
        board[x][j] = 0;
    }
  }
  else if (dir == 2)
  // S
  {
    for (int i = x + 1; i < n; i++)
    {
      if (board[i][y] == 6)
        break;
      if (board[i][y] == set)
        board[i][y] = 0;
    }
  }
  else if (dir == 3)
  // E
  {
    for (int j = y + 1; j < m; j++)
    {
      if (board[x][j] == 6)
        break;
      if (board[x][j] == set)
        board[x][j] = 0;
    }
  }
}