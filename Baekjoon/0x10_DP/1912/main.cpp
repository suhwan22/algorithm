#include <iostream>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  int max = -2147483648;
  int input;
  int cur = -2147483648;
  cin >> n;
  while (n--)
  {
    cin >> input;
    if (cur < 0)
      cur = input;
    else
      cur += input;
    if (cur > max)
      max = cur;
  }

  cout << max;

  return 0;
}