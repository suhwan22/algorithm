#include <iostream>
#include <cmath>

using namespace std;

int cal(int n, int r, int c)
{
  if (n == 0)
    return 0;
  int h = 1<<(n - 1);
  if (r < h && c < h) return cal(n-1, r, c);
  else if (r < h && c >= h) return h * h + cal(n - 1, r, c - h);
  else if (r >= h && c < h) return 2 * h * h + cal(n - 1, r - h, c);
  else return 3 * h * h + cal(n-1, r - h ,c - h);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  // 이건 실제로 square 를 그리지 않고 단순히 n번째만 계산하는걸 고려하고 짜야함
  // 위 코드 바킹독 참고
  int n, r, c;
  cin >> n >> r >> c;

  cout << cal(n, r, c);

  return 0;
}