#include <iostream>
#include <queue>

using namespace std;

int n, k;
char board[101][101] = {};
queue<pair<int, char>> q;
deque<pair<int, int>> snake;

bool isAlive(int x, int y);
void printBoard();

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
      board[i][j] = ' ';
  }
  int r, c;
  for (int i = 0; i < k; i++)
  {
    cin >> r >> c;
    board[r][c] = '%';
  }

  int l;
  cin >> l;
  pair<int, char> cmd;
  for (int i = 0; i < l; i++)
  {
    cin >> cmd.first >> cmd.second;
    q.push(cmd);
  }

  snake.push_back({1, 1});
  board[1][1] = '*';
  int nx, ny;
  int dir = 0;
  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};
  int time = 0;

  cmd = q.front();
  q.pop();
  while (1)
  {
    cout << "time: " << time << ", dir: " << dir << "\n";
    printBoard();
    if (cmd.first < time && !q.empty())
    {
      cmd = q.front();
      q.pop();
    }
    if (cmd.first == time)
      dir = cmd.second == 'D' ? (dir == 3 ? 0 : dir + 1) : (dir == 0 ? 3 : dir - 1);
    nx = snake.front().first + dx[dir];
    ny = snake.front().second + dy[dir];
    if (!isAlive(nx, ny))
      break;
    snake.push_front({nx, ny});
    if (board[nx][ny] != '%')
    {
      board[snake.back().first][snake.back().second] = ' ';
      snake.pop_back();
    }
    board[nx][ny] = '*';
    time++;
  }

  cout << time + 1;

  return 0;
}

bool isAlive(int x, int y)
{
  if (x < 1 || y < 1 || x > n || y > n) 
    return false;
  if (board[x][y] == '*') 
    return false;
  return true;
}

void printBoard()
{
  for (int i = 0; i < n + 2; i++)
    cout << "-";
  cout << "\n";
  for (int i = 1; i <= n; i++)
  {
    cout << "|";
    for (int j = 1; j <= n; j++)
      cout << board[i][j];
    cout << "|\n";
  }
  for (int i = 0; i < n + 2; i++)
    cout << "-";
  cout << "\n";
}