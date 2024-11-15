#include <iostream>

using namespace std;

int D[1500051] = {};

// 지금 계산한 값을 i + t 로 보냄, 큰 값 저장

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, t, p;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> t >> p;
    D[i] = D[i] < D[i-1] ? D[i-1] : D[i];
    D[i + t - 1] = D[i + t - 1] > D[i - 1] + p ? D[i + t - 1] : D[i - 1] + p;
  }

  cout << D[n];

  return 0;
}