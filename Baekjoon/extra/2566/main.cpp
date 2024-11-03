#include <iostream>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a;
  int max = -1;
  int x = -1, y = 0;

  for (int i = 1; i <= 9; i++)
  {
    for (int j = 1; j <= 9; j++)
    {
      cin >> a;
      if (max < a)
      {
        max = a;
        x = i;
        y = j;
      }
    }
  }
  cout << max << "\n" << x << " " << y;
  return 0;
}