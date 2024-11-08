#include <iostream>

using namespace std;

char board[10][10] = {};
int n, m;
int rX, rY, bX, bY, eX, eY;
int min = -1;

void down();
void up();
void left();
void right();
void printBoard();
void dfs(int depth);

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> m;
  // 3 <= n, m <= 10

  string input;
  for (int i = 0; i < n; i++)
  {
    cin >> input;
    for (int j = 0; j < m; j++)
    {
      if (input[j] == 'O')
      {
        eX = i;
        eY = j;
      }
      else if (input[j] == 'R')
      {
        rX = i;
        rY = j;
      }
      else if (input[j] == 'B')
      {
        bX = i;
        bY = j;
      }
      if (input[j] == '#')
        board[i][j] = '#';
      else
        board[i][j] = '.';
    }
  }
  dfs(0);
  cout << ::min;

  return 0;
}

void printBoard()
{
  cout << "-----------------\n";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (i == rX && j == rY)
        cout << "R";
      else if (i == bX && j == bY)
        cout << "B";
      else if (i == eX && j == eY)
        cout << "O";
      else
        cout << board[i][j];
    }
    cout << "\n";
  }
  cout << "-----------------\n";
}

void dfs(int depth)
{
  if (depth > 10)
    return ;
  if (bX == eX && bY == eY)
    return ;
  if (rX == eX && rY == eY)
  {
    if (::min == -1 || ::min > depth)
      ::min = depth;
    return ;
  }
  int curBX = bX;
  int curBY = bY;
  int curRX = rX;
  int curRY = rY;
  down();
  dfs(depth + 1);
  bX = curBX;
  bY = curBY;
  rX = curRX;
  rY = curRY;

  up();
  dfs(depth + 1);
  bX = curBX;
  bY = curBY;
  rX = curRX;
  rY = curRY;

  right();
  dfs(depth + 1);
  bX = curBX;
  bY = curBY;
  rX = curRX;
  rY = curRY;

  left();
  dfs(depth + 1);
  bX = curBX;
  bY = curBY;
  rX = curRX;
  rY = curRY;
}

void down()
{
  if (rX > bX)
  {
    for (int i = rX; i < n; i++)
    {
      if (i == eX && rY == eY)
      {
        rX = i;
        break;
      }
      if (board[i][rY] != '.')
      {
        rX = i - 1;
        break;
      }
    }
    for (int i = bX; i < n; i++)
    {
      if (i == eX && bY == eY)
      {
        bX = i;
        break;
      }
      if (board[i][bY] != '.' || (i == rX && bY == rY))
      {
        bX = i - 1;
        break;
      }
    }
  }
  else
  {
    for (int i = bX; i < n; i++)
    {
      if (i == eX && bY == eY)
      {
        bX = i;
        break;
      }
      if (board[i][bY] != '.')
      {
        bX = i - 1;
        break;
      }
    }
    for (int i = rX; i < n; i++)
    {
      if (i == eX && rY == eY)
      {
        rX = i;
        break;
      }
      if (board[i][rY] != '.' || (i == bX && rY == bY))
      {
        rX = i - 1;
        break;
      }
    }
  }
}

void up()
{
  if (rX < bX)
  {
    for (int i = rX; i >= 0; i--)
    {
      if (i == eX && rY == eY)
      {
        rX = i;
        break;
      }
      if (board[i][rY] != '.')
      {
        rX = i + 1;
        break;
      }
    }
    for (int i = bX; i >= 0; i--)
    {
      if (i == eX && bY == eY)
      {
        bX = i;
        break;
      }
      if (board[i][bY] != '.' || (i == rX && bY == rY))
      {
        bX = i + 1;
        break;
      }
    }
  }
  else
  {
    for (int i = bX; i >= 0; i--)
    {
      if (i == eX && bY == eY)
      {
        bX = i;
        break;
      }
      if (board[i][bY] != '.')
      {
        bX = i + 1;
        break;
      }
    }
    for (int i = rX; i >= 0; i--)
    {
      if (i == eX && rY == eY)
      {
        rX = i;
        break;
      }
      if (board[i][rY] != '.' || (i == bX && rY == bY))
      {
        rX = i + 1;
        break;
      }
    }
  }
}

void right()
{
  if (rY > bY)
  {
    for (int i = rY; i < m; i++)
    {
      if (i == eY && rX == eX)
      {
        rY = i;
        break;
      }
      if (board[rX][i] != '.')
      {
        rY = i - 1;
        break;
      }
    }
    for (int i = bY; i < m; i++)
    {
      if (i == eY && bX == eX)
      {
        bY = i;
        break;
      }
      if (board[bX][i] != '.' || (i == rY && bX == rX))
      {
        bY = i - 1;
        break;
      }
    }
  }
  else
  {
    for (int i = bY; i < m; i++)
    {
      if (i == eY && bX == eX)
      {
        bY = i;
        break;
      }
      if (board[bX][i] != '.')
      {
        bY = i - 1;
        break;
      }
    }
    for (int i = rY; i < m; i++)
    {
      if (i == eY && rX == eX)
      {
        rY = i;
        break;
      }
      if (board[rX][i] != '.' || (i == bY && rX == bX))
      {
        rY = i - 1;
        break;
      }
    }
  }
}

void left()
{
  if (rY < bY)
  {
    for (int i = rY; i >= 0; i--)
    {
      if (i == eY && rX == eX)
      {
        rY = i;
        break;
      }
      if (board[rX][i] != '.')
      {
        rY = i + 1;
        break;
      }
    }
    for (int i = bY; i >= 0; i--)
    {
      if (i == eY && bX == eX)
      {
        bY = i;
        break;
      }
      if (board[bX][i] != '.' || (i == rY && bX == rX))
      {
        bY = i + 1;
        break;
      }
    }
  }
  else
  {
    for (int i = bY; i >= 0; i--)
    {
      if (i == eY && bX == eX)
      {
        bY = i;
        break;
      }
      if (board[bX][i] != '.')
      {
        bY = i + 1;
        break;
      }
    }
    for (int i = rY; i >= 0; i--)
    {
      if (i == eY && rX == eX)
      {
        rY = i;
        break;
      }
      if (board[rX][i] != '.' || (i == bY && rX == bX))
      {
        rY = i + 1;
        break;
      }
    }
  }
}