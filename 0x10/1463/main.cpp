#include <iostream>

using namespace std;

//D[i] = i 가 1위 되는데 걸리는 횟수 라하자
//D[12] = min(D[4] + 1, D[6] + 1, D[11] + 1)
//D[k] = min(D[k/3] + 1, D[k/2] + 1, D[k-1] + 1)
// 이런 느낌으로 점화식 세우고 저장하는 듯

int D[1000001] = {};

int main()
{
  int n;
  cin >> n;

  D[1] = 0;
  for (int i = 2; i <= n; i++)
  {
    D[i] = D[i - 1] + 1;
    if (i % 2 == 0) D[i] = min(D[i], D[i/2] + 1);
    if (i % 3 == 0) D[i] = min(D[i], D[i/3] + 1);
  }

  cout << D[n];
}