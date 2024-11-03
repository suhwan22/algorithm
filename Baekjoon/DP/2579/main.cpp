#include <iostream>

using namespace std;

int step[301];
int d[301][3] = {};

// d[i][j] = i번째 계단을 밟는데 지금까지 연속해서 j개 밟음
// d[1][1] = 1번째 계단을 밟는데 1개 밟음
// d[2][1] = 2번째 계단을 밟는데 1개 밟음
// d[2][2] = 2번째 게단을 밟는데 2개 밟음

// a1, a2, a3, a4, a5 ...

// d[1][1] = a1
// d[2][1] = a2
// d[2][2] = a1 + a2
// d[3][1] = a1 + a3
// d[3][2] = a2 + a3
// d[4][1] = max(a1+a2+a4, a2+a4)
// d[4][2] = a1+a3+a4
// d[5][1] = max(a1+a3+a5, a2+a3+a5) -> max(d[3][1], d[3][2]) + a5
// d[5][2] = max(a1+a2+a4+a5, a2+a4+a5) -> d[4][1] + a5
// d[6][1] = max(a1+a2+a4+a6, a2+a4+a6) -> max(d[4][1]. d[4][2]) + a6
// d[6][2] = max(a1+a3+a5+a6, a2+a3+a5+a6) -> d[5][1] + a6

// d[n][1] = max(d[n-2][1], d[n-2][2]) + step[n]
// d[n][2] = d[n-1][1] + step[n]


int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> step[i];
  
  d[1][1] = step[1];
  d[2][1] = step[2];
  d[2][2] = step[1] + step[2];

  for (int i = 3; i <= n; i++)
  {
    d[i][1] = max(d[i - 2][1], d[i - 2][2]) + step[i];
    d[i][2] = d[i - 1][1] + step[i];
  }

  cout << max(d[n][1], d[n][2]);

  return 0;
}