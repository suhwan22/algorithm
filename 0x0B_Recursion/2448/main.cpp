#include <iostream>

using namespace std;

// 3 * 2^10 = 3072
char str[1024 * 3][1024 * 6] = {};

void func(int l, int x, int y)
{
  if (l == 6)
  {
    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 6; j++)
      {
        if (i == 0 && j != 5)
          str[x + i][y + j] = '*';
        else if (i == 1 && j != 0 && j != 2 && j != 4 && j != 5)
          str[x + i][y + j] = '*';
        else if (i == 2 && j == 2)
          str[x + i][y + j] = '*';
      }
    }
    return ;
  }
  func(l / 2, x, y);
  func(l / 2, x, y + l / 2);
  func(l / 2, x + l / 4, y + l / 4);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  // n == 3 x 2^n triangle
  //   *
  //  * *
  // *****
  // len = n / 3 * 6

  func(n / 3 * 6, 0, 0);
  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = 0; j < n / 3 * 6; j++)
    {
      if (str[i][j] == '*')
        cout << '*';
      else
        cout << ' ';
      if (j == n / 3 * 6 - 1)
        cout << "\n";
    }
  }

  return 0;
}