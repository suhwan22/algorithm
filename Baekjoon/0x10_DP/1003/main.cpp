#include <iostream>

using namespace std;

int D[41][41] = {};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;

  D[0][0] = 1;
  D[1][0] = 0;
  D[1][1] = 1;
  D[2][0] = 1;
  D[2][1] = 1;
  for (int i = 3; i < 41; i++)
  {
    D[i][0] = D[i-1][0] + D[i-2][0];
    D[i][1] = D[i-1][1] + D[i-2][1];
  }

  int input;
  while (n--)
  {
    cin >> input;
    cout << D[input][0] << " " << D[input][1] << "\n";
  }

  return 0;
}