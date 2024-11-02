#include <iostream>

using namespace std;

int board[20][20] = {};
int dice[6] = {};
//   1
// 3 0 2  0 은 바닥
//   4
//   5

int n, m, k;

int diceX, diceY;

void moveDice(int dir);

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> diceX >> diceY >> k;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
      cin >> board[i][j];
  }

  int dir;

  // for (int i = 0; i < n; i++)
  // {
  //   for (int j = 0; j < m; j++)
  //     cout << board[i][j] << " ";
  //   cout << "\n";
  // }

  while (k--)
  {
    cin >> dir;
    moveDice(dir);
    // cout << "[moveDice]: diceX: " << diceX << ", diceY: " << diceY << "\n";
    // cout << "  " << dice[1] << "\n"
    //     << dice[3]<< " " << dice[0] << " " << dice[2] << "\n"
    //     << "  " << dice[4] << "\n" << "  " << dice[5] << "\n";
    // cout << "[board]\n";
    // for (int i = 0; i < n; i++)
    // {
    //   for (int j = 0; j < m; j++)
    //     cout << board[i][j] << " ";
    //   cout << "\n";
    // }
  }

  return 0;
}

//   1
// 3 0 2  0 은 바닥
//   4
//   5
void moveDice(int dir)
{
  int nx, ny;
  int temp;
  if (dir == 1) // 동쪽
  {
    //3 0 2 5 , 2가 다음 바닥
    nx = diceX;
    ny = diceY + 1;
    if (nx < 0 || ny < 0 || nx >= n || ny >= m) return ;
    temp = dice[0];
    dice[0] = dice[2];
    dice[2] = dice[5];
    dice[5] = dice[3];
    dice[3] = temp;
    if (board[nx][ny] == 0)
    {
      board[nx][ny] = dice[0];
    }
    else
    {
      dice[0] = board[nx][ny];
      board[nx][ny] = 0;
    }
    diceX = nx;
    diceY = ny;
    cout << dice[5] << "\n";
  }
  else if (dir == 2) // 서쪽
  {
    //3 0 2 5 , 3 이 다음 바닥
    nx = diceX;
    ny = diceY - 1;
    if (nx < 0 || ny < 0 || nx >= n || ny >= m) return ;
    temp = dice[0];
    dice[0] = dice[3];
    dice[3] = dice[5];
    dice[5] = dice[2];
    dice[2] = temp;
    if (board[nx][ny] == 0)
    {
      board[nx][ny] = dice[0];
    }
    else
    {
      dice[0] = board[nx][ny];
      board[nx][ny] = 0;
    }
    diceX = nx;
    diceY = ny;
    cout << dice[5] << "\n";
  }
  else if (dir == 3) // 북쪽
  {
    // 1 0 4 5 , 1이 다음 바닥
    nx = diceX - 1;
    ny = diceY;
    if (nx < 0 || ny < 0 || nx >= n || ny >= m) return ;
    temp = dice[0];
    dice[0] = dice[1];
    dice[1] = dice[5];
    dice[5] = dice[4];
    dice[4] = temp;
    if (board[nx][ny] == 0)
    {
      board[nx][ny] = dice[0];
    }
    else
    {
      dice[0] = board[nx][ny];
      board[nx][ny] = 0;
    }
    diceX = nx;
    diceY = ny;
    cout << dice[5] << "\n";
  }
  else if (dir == 4) // 남쪽
  {
    // 1 0 4 5, 4가 다음 바닥
    nx = diceX + 1;
    ny = diceY;
    if (nx < 0 || ny < 0 || nx >= n || ny >= m) return ;
    temp = dice[0];
    dice[0] = dice[4];
    dice[4] = dice[5];
    dice[5] = dice[1];
    dice[1] = temp;
    if (board[nx][ny] == 0)
    {
      board[nx][ny] = dice[0];
    }
    else
    {
      dice[0] = board[nx][ny];
      board[nx][ny] = 0;
    }
    diceX = nx;
    diceY = ny;
    cout << dice[5] << "\n";
  }
}