#include <iostream>

using namespace std;

int board[100000] = {};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> board[i];
  
  int st = 0, en = 0;
  int min = 0;
  int sum = 0;
  while (st < n && en <= n)
  {
    cout << "sum: " << sum << ", st: " << st << ", en: " << en << "\n";
    if (sum >= m)
    {
      if (min == 0 || min > en - st)
        min = en - st;
      sum -= board[st++];
    }
    else
      sum += board[en++];
    if (min == 1)
      break;
  }

  cout << min;

  return 0;
}