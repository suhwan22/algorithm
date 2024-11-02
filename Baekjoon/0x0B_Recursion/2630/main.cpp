#include <iostream>

using namespace std;

int a = 0, b = 0;
char board[128][128];

bool f(int n, int x, int y)
{
  char flag = board[x][y];
  for (int i = x; i < x + n; i++)
  {
    for (int j = y; j < y + n; j++)
    {
      if (flag != board[i][j])
        return false;
    }
  }
  if (flag == 0)
    a++;
  else if (flag == 1)
    b++;
  return true;
}

void func(int n, int x, int y)
{
  if (f(n, x, y))
    return ;
  func(n / 2, x, y);
  func(n / 2, x, y + n / 2);
  func(n / 2, x + n / 2, y);
  func(n / 2, x + n / 2, y + n / 2);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  // n x n square

  int input;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> input;
      board[i][j] = input;
    }
  }

  func(n, 0, 0);
  cout << a << "\n" << b;

  return 0;
}