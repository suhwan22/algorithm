#include <iostream>

using namespace std;

// 1 : 1 2 3 4 5 6 7 8 9 -> 9
// 2 : 10 12 21 23 32 34 43 45 54 56 65 67 76 78 87 89 98 -> 17
// 3 : 101 121 123 210 212 232 234 (2~7 4개씩) 878 876 898 989 987  -> 3 + 24 + 3 + 2 -> 32
// 4 : 1 010 012,  

// n번째 : 1로 시작 -> n-2의 1 시작 + n-1의 2시작
//      : 2로 시작 -> n-1의 1 시작 + n-2의 3시작
// n번째 m(1~9)으로 시작하는 계단수는?
// D[n][m] = D[n-1][m-1] + D[n-1][m+1]
// m == 0 인 경우는 이전의 1의 경우로 채우고, m == 10인 경우는 0으로 하자

long long D[101][11] = {};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      if (i == 1)
        D[i][j] = 1;
      else if (j == 0)
        D[i][j] = D[i - 1][1];
      else
        D[i][j] = (D[i - 1][j - 1] + D[i - 1][j + 1]) % 1000000000;
    }
  }

  long long ans = 0;
  for (int i = 1; i < 10; i++)
    ans = (ans + D[n][i]) % 1000000000;
  
  cout << ans;

  return 0;
}