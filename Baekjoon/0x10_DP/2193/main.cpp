#include <iostream>

using namespace std;

long long D[90][2] = {};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  D[1][1] = 1;
  D[2][0] = 1;
  D[3][0] = 1;
  D[3][1] = 1;

  for (int i = 4; i <= n; i++)
  {
    D[i][0] = D[i-1][0] + D[i-1][1];
    D[i][1] = D[i-1][0];
  }

  for (int i = 1; i <= n; i++)
    cout << D[i][0] + D[i][1] << "\n";

  return 0;
}