#include <iostream>

using namespace std;

// D[n][m]
// n: n장 카드팩 까지를 고려한 경우
// m: 지금 까지 구매한 카드 개수
int D[1001][1001] = {};

int n;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int input;
  int ans = 0;
  for (int i = 1; i <= n; i++)
  {
    cin >> input;
    for (int cnt = 1; i * cnt <= n; cnt++)
    {
      // cnt: i개 들어있는 카드를 cnt개 사는 경우
      for (int total = 1; total <= n; total++)
      {
        // total: 총 total개 구매한 경우
        if (cnt * i > total)
          D[i][total] = max(D[i-1][total], D[i][total]);
        else
          D[i][total] = max(max(D[i-1][total - cnt * i] + cnt * input, D[i-1][total]), D[i][total]);
      }
    }
    ans = max(D[i][n], D[i-1][n]);
  }

  cout << ans;

  return 0;
}