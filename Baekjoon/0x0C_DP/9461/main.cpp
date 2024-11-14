#include <iostream>

using namespace std;

long long D[101] = {};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  D[1] = 1;
  D[2] = 1;
  for (int i = 3; i <= 100; i++)
    D[i] = D[i - 2] + D[i - 3];
  
  int n;
  cin >> n;
  int k;
  while (n--)
  {
    cin >> k;
    cout << D[k] << "\n";
  }

  return 0;
}