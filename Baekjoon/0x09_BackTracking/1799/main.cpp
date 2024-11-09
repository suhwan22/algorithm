#include <iostream>

using namespace std;

int n;
bool en[10][10] = {};
bool vis[19] = {};

// k 의 순서
// 0 1 2 3
// 1 2 3 4
// 2 3 4 5
// 3 4 5 6

// 대각선 개수 = 2 * (n - 1) + 1
// \ 가 일치하는 좌표 y - x + n - 1
// / 가 일치하는 좌표 x + y

// 0 ~ 2 * (n - 1)번째 / 대각 선은 선택한다.
// k 번 째 대각선을 선택할 차례라면
// k < n 까지는 x의 시작 점 증가, 그다음 부터는 n - 1로 고정
// (k, 0) ~ (0, k)
// k >= n
// (n - 1, k - n + 1) ~ (k - n + 1, n - 1)

// x, y -> vis[y - x + n - 1] = true;

int max = 0;

void dfs(int k, int cnt);

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cin >> en[i][j];
  }
  dfs(0, 0);
  cout << ::max;

  return 0;
}

void dfs(int k, int cnt)
{
  if (k >= 2 * (n - 1) + 1)
  {
    ::max = cnt > ::max ? cnt : ::max;
    return ;
  }
  bool flag = false;
  if (k < n)
  {
    for (int x = k, y = 0; x >= 0; x--, y++)
    {
      if (vis[y - x + n - 1]) continue;
      if (en[x][y] == 0) continue;
      vis[y - x + n - 1] = true;
      flag = true;
      dfs(k + 1, cnt + 1);
      vis[y - x + n - 1] = false;
    }
  }
  else
  {
    for (int x = n - 1, y = k - n + 1; y < n; x--, y++)
    {
      if (vis[y - x + n - 1]) continue;
      if (en[x][y] == 0) continue;
      vis[y - x + n - 1] = true;
      flag = true;
      dfs(k + 1, cnt + 1);
      vis[y - x + n - 1] = false;
    }
  }
  if (!flag)
    dfs(k+1, cnt);
}