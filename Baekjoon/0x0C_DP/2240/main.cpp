#include <iostream>

using namespace std;

int t, w;
// t: 자두 떨어지는 시간 (1 <= t <= 1,000)
// w: 움직일 수 있는 기회 (1 <= w <= 30)

int board[1001] = {};
int D[2][32][1001] = {};

// D[n][w][t] : n 현재 위치 (0: 1, 1: 2), w: 남은 이동가능 횟수, t: 현재 시간
// D[n][w][t] = max(D[n][w][t-1], D[!n][w+1][t-1]) + board[t];
// t-1에서 이동을 해서 n으로 오는 경우와 w는 지금과 같고 그자리에 있는 경우중에 큰거를 선택


int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t >> w;
  for (int i = 1; i <= t; i++)
    cin >> board[i];
  
  for (int i = 1; i <= t; i++)
  {
    for (int j = 0; j <= w; j++)
      D[0][j][i] = max(D[0][j][i-1], D[1][j+1][i-1]) + (board[i] == 1 ? 1 : 0);
    for (int j = 0; j < w; j++)
      D[1][j][i] = max(D[0][j+1][i-1], D[1][j][i-1]) + (board[i] == 2 ? 1 : 0);
  }

  int max = 0;
  for (int i = 0; i <= w; i++)
  {
    for (int n = 0; n < 2; n++)
    {
      if (max < D[n][i][t])
        max = D[n][i][t];
    }
  }

  cout << max;

  return 0;
}