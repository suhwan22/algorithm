#include <iostream>

using namespace std;

int a = 0, b = 0, c = 0;
char board[6561][6561];

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
  if (flag == -1)
    a++;
  else if (flag == 0)
    b++;
  else if (flag == 1)
    c++;
  return true;
}

void func(int n, int x, int y)
{
  if (f(n, x, y))
    return ;
  func(n / 3, x, y);
  func(n / 3, x + n / 3, y);
  func(n / 3, x + 2 * n / 3, y);
  func(n / 3, x, y + n / 3);
  func(n / 3, x + n / 3, y + n / 3);
  func(n / 3, x + 2 * n / 3, y + n / 3);
  func(n / 3, x, y + 2 * n / 3);
  func(n / 3, x + n / 3, y + 2 * n / 3);
  func(n / 3, x + 2 * n / 3, y + 2 * n / 3);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  // n x n square
  // 43 MB

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
  cout << a << "\n" << b << "\n" << c;

  return 0;
}