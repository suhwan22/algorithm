#include <iostream>

using namespace std;

char board[64][64];

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
  if (flag == '0')
    cout << "0";
  else if (flag == '1')
    cout << "1";
  return true;
}

int cnt = 0;

void func(int n, int x, int y)
{
  if (f(n, x, y))
    return ;
  cout << "(";
  func(n / 2, x, y);
  func(n / 2, x, y + n / 2);
  func(n / 2, x + n / 2, y);
  func(n / 2, x + n / 2, y + n / 2);
  cout << ")";
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  // n x n square

  string input;
  for (int i = 0; i < n; i++)
  {
    cin >> input;
    for (int j = 0; j < n; j++)
    {
      board[i][j] = input.at(j);
    }
  }

  func(n, 0, 0);

  return 0;
}