#include <iostream>
#include <map>

using namespace std;

int n, m, t;
int board[51][51] = {};
int purifier = 0;

void fineDust();
void purifyUp();
void purifyDown();

void printBoard();

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> t;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      cin >> board[i][j];
      if (board[i][j] == -1 && purifier == 0)
        purifier = i;
    }
  }
  // cout << "purifer: " << purifier << "\n";
  // printBoard();
  while (t--)
  {
    fineDust();
    purifyUp();
    purifyDown();
    // printBoard();
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (board[i][j] <= 0) continue;
      ans += board[i][j];
    }
  }
  cout << ans;

  return 0;
}

void fineDust()
{
  int nx, ny;
  int dx[4] = {0, 1, -1, 0};
  int dy[4] = {1, 0, 0, -1};
  int diff[51][51] = {};
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (board[i][j] <= 0) continue;
      int cnt = 0;
      for (int k = 0; k < 4; k++)
      {
        nx = i + dx[k];
        ny = j + dy[k];
        if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
        if ((nx == purifier || nx == purifier + 1) && ny == 1) continue;
        diff[nx][ny] += board[i][j]/5;
        cnt++;
      }
      diff[i][j] -= cnt * (board[i][j]/5);
    }
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
      board[i][j] += diff[i][j];
  }
}

void purifyUp()
{
  int x = purifier;
  for (int i = x; i > 1; i--)
    board[i][1] = board[i-1][1];
  board[x][1] = 0;
  for (int j = 1; j < m; j++)
    board[1][j] = board[1][j+1];
  for (int i = 1; i < x; i++)
    board[i][m] = board[i+1][m];
  for (int j = m; j > 1; j--)
    board[x][j] = board[x][j-1];
}

void purifyDown()
{
  int x = purifier + 1;
  for (int i = x; i < n; i++)
    board[i][1] = board[i+1][1];
  board[x][1] = 0;
  for (int j = 1; j < m; j++)
    board[n][j] = board[n][j+1];
  for (int i = n; i > x; i--)
    board[i][m] = board[i-1][m];
  for (int j = m; j > 1; j--)
    board[x][j] = board[x][j-1];
}

void printBoard()
{
  cout << "-----------------------\n";
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if ((i == purifier || i == purifier + 1) && j == 1)
        cout << "X ";
      else
        cout << board[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "-----------------------\n";
}