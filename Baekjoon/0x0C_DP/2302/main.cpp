#include <iostream>

using namespace std;

bool vip[41] = {};
int D[41] = {};
int n, m;

// D[0] = 1
// D[1] = 1
// D[2] = 2
// n > 2
// D[n] = D[n-1] + D[n-2]

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  int input;
  for (int i = 0; i < m; i++)
  {
    cin >> input;
    vip[input] = true;
  }

  D[0] = 1;
  D[1] = 1;
  D[2] = 2;

  for (int i = 3; i <= n; i++)
    D[i] = D[i-1] + D[i-2];

  long long ans = 1;
  int cnt = 0;
  for (int i = 1; i <= n+1; i++)
  {
    if (vip[i] || i == n+1)
    {
      ans *= D[cnt];
      cnt = 0;
    }
    else
      cnt++;
  }

  cout << ans;

  return 0;
}