#include <iostream>
#include <algorithm>

using namespace std;

int D[1001][1001] = {};

// D[n][m] = (D[n-1][m-1] + 1) or 0;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string str1, str2;

  cin >> str1 >> str2;

  string big, small;
  big = str1.length() > str2.length() ? str1 : str2;
  small = str1.length() > str2.length() ? str2 : str1;

  int max = 0;

  for (int i = 0; i < (int)small.length(); i++)
  {
    for (int j = 0; j < (int)big.length(); j++)
    {
      if (big[j] == small[i])
      {
        D[i+1][j+1] = D[i][j] + 1;
        if (max < D[i+1][j+1])
          max = D[i+1][j+1];
      }
      else
        D[i+1][j+1] = D[i+1][j] > D[i][j+1] ? D[i+1][j] : D[i][j+1];
    }
  }

  for (int i = 0; i <= (int)small.length(); i++)
  {
    for (int j = 0; j <= (int)big.length(); j++)
      cout << D[i][j] << " ";
    cout << "\n";
  }

  cout << max;

  return 0;
}