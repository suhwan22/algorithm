#include <iostream>

using namespace std;

long long D[91] = {};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  D[0] = 0;
  D[1] = 1;
  D[2] = 1;
  for (int i = 3;i <= n; i++)
    D[i] = D[i-2] + D[i-1];

  cout << D[n];

  return 0;
}