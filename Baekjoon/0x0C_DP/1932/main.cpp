#include <iostream>

using namespace std;

//        0
//       0 1
//      0 1 2
//     0 1 2 3
//    0 1 2 3 4

int D[500][500] = {};
int tri[500][500] = {};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= i; j++)
      cin >> tri[i][j];
  }

  D[0][0] = tri[0][0];

  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      if (j == 0)
        D[i][j] = D[i-1][j] + tri[i][j];
      else if (j == i)
        D[i][j] = D[i-1][j-1] + tri[i][j];
      else
        D[i][j] = max(D[i-1][j-1], D[i-1][j]) + tri[i][j];
    }
  }

  int out = -1;
  for (int i = 0; i < n; i++)
  {
    if (out < D[n-1][i])
      out = D[n-1][i];
  }

  cout << out;

  return 0;
}