#include <iostream>

using namespace std;

long long cal(long long a, long long b, long long c)
{
  if (b == 1)
    return a % c;
  long long v = cal(a, b/2, c);
  v = v * v % c;
  if (b % 2 == 0)
    return v;
  return v * a % c;
}

// a^2k % c == (a^k % c) * (a^k % c) % c
// 이게 점화식임

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  long long a, b, c;
  cin >> a >> b >> c;

  cout << cal(a, b, c);

  return 0;
}