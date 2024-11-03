#include <iostream>

using namespace std;

char str[2718][2718] = {};

void func(int size, int n, int x , int y, char c)
{
  if (n == 1)
  {
    str[x][y] = c;
    return ;
  }
  func(size, n / 3, x, y, c);
  func(size, n / 3, x, y + n / 3, c);
  func(size, n / 3, x, y + 2 * n / 3, c);

  func(size, n / 3, x + n / 3, y, c);
  func(size, n / 3, x + n / 3, y + n / 3, ' ');
  func(size, n / 3, x + n / 3, y + 2 * n / 3, c);

  func(size, n / 3, x + 2 * n / 3, y, c);
  func(size, n / 3, x + 2 * n / 3, y + n / 3, c);
  func(size, n / 3, x + 2 * n / 3, y + 2 * n / 3, c);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  // n x n square
  // ***
  // * *
  // ***

  func(n, n, 0, 0, '*');
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cout << str[i][j];
    cout << "\n";
  }

  return 0;
}