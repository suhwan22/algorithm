#include <iostream>

using namespace std;

long long D[2501] = {};
long long mod = 1000000007;

int main(void) { 
  cin.tie(0)->sync_with_stdio(0);
  int n, t;
  cin >> t;

  D[0] = 1;
  D[1] = 1;
  for (int i = 2; i <= 2500; i++)
  {
    for (int j = i - 1; j > 0; j--)
        D[i] = (D[i] + D[j - 1] * D[i - j]) % mod;
    D[i] = (D[i] + D[i-1]) % mod;
  }
  while (t--)
  {
    cin >> n;
    if (n % 2 == 1)
      cout << "0\n";
    else
      cout << D[n/2] << "\n";
  }
   
  return 0;
}
