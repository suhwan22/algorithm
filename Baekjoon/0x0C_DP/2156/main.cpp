#include <iostream>
#include <algorithm>

using namespace std;

int D[10001][3] = {};
int wine[10001] = {};

// D[1][1] = wine[1]

// D[2][0] = D[1][1]
// D[2][1] = wine[2]
// D[2][2] = D[1][1] + wine[2]

// D[3][0] = max(D[2][1], D[2][2])
// D[3][1] = max(D[1][1], D[1][2]) + wine[3]
// D[3][2] = D[2][1] + wine[3]

// D[4][0] = max(D[3][1], D[3][2])
// D[4][1] = max(D[2][1~2]) + wine[4]
// D[4][2] = D[3][1] + wine[4]

// D[5][0] = max(D[4][1], D[4][2])
// D[5][1] = max(D[3][1~2]) + wine[5]
// D[5][2] = D[4][1] + wine[5]

// D[6][0] = max(D[5][1], D[5][2])
// D[6][1] = max(D[4][1~2]) + wine[6]
// D[6][2] = D[5][1] + wine[6]

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> wine[i];

  int ans = 0;

  if (n < 3)
  {
    for (int i = 1; i <= n; i++)
      ans += wine[i];
    cout << ans;
    return 0;
  }


  D[1][1] = wine[1];
  D[2][1] = wine[2];
  D[2][2] = D[1][1] + wine[2];
  ans = max({D[1][1], D[2][1], D[2][2]});
  for (int i = 3; i <= n; i++)
  {
    D[i][0] = max({D[i-1][0], D[i-1][1], D[i-1][2]});
    D[i][1] = max({D[i-2][0], D[i-2][1], D[i-2][2]}) + wine[i];
    D[i][2] = D[i-1][1] + wine[i];
    if (ans < max({D[i][0],D[i][1], D[i][2]}))
      ans = max({D[i][0], D[i][1], D[i][2]});
  }

  for (int i = 1; i <= n; i++)
    cout << i << ": " << D[i][0] << " " << D[i][1] << " " << D[i][2] << "\n";
  cout << ans;

  return 0;
}