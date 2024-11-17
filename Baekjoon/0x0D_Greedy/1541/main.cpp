#include <iostream>
#include <sstream>

using namespace std;

// + 를 전부 진행하고 - 를 하면 된다.

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string input;
  cin >> input;
  int sum = 0;
  int minus = 0;
  bool visMinus = false;

  int n = 0;
  int i = 0;
  while (i < (int)input.length() && isdigit(input[i]))
    n = n * 10 + input[i++] - '0';
  sum = n;
  n = 0;
  cout << "init: " << sum << "\n";
  while (i < (int)input.length())
  {
    if (input[i] == '+')
    {
      i++;
      while (i < (int)input.length() && isdigit(input[i]))
        n = n * 10 + input[i++] - '0';
      cout << " + " << n << "\n";
      if (visMinus)
      {
        minus += n;
        n = 0;
      }
      else
      {
        sum += n;
        n = 0;
      }
    }
    else if (input[i] == '-')
    {
      i++;
      while (i < (int)input.length() && isdigit(input[i]))
        n = n * 10 + input[i++] - '0';
      cout << " - " << n << "\n";
      if (visMinus)
      {
        sum -= minus;
        minus = n;
        n = 0;
      }
      else
      {
        visMinus = true;
        minus = n;
        n = 0;
      }
    }
  }

  if (visMinus)
    sum -= minus;

  cout << sum;

  return 0;
}