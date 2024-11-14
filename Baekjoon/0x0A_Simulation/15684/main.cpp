#include <iostream>

using namespace std;

// 최대 경우의 수  (2 ≤ N ≤ 10, 1 ≤ H ≤ 30, 0 ≤ M ≤ (N-1)×H)
// 에서 M의 최대값이 270이고
// 270개 중에서 1개 고르는 경우 270C1 + 2개 고르는 경우 270C2 + 3개 고르는 경우 270C3
// => 3280725

bool edge[31][11] = {};
int n, m, h;
int min = -1;

bool isValid();
void dfs(int x, int y, int sel);

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> h;

  int x, y;
  for (int i = 0; i < m; i++)
  {
    cin >> x >> y;
    edge[x][y] = true;
  }

  if (isValid())
  {
    cout << 0;
    return 0;
  }
  for (int i = 1; i <= h; i++)
  {
    for (int j = 1; j < n; j++)
    {
      if (edge[i][j]) continue;
      edge[i][j] = true;
      dfs(i, j, 1);
      edge[i][j] = false;
    }
  }
  cout << ::min;

  return 0;
}

void dfs(int x, int y, int sel)
{
  if (sel > 3)
    return ;
  if (isValid())
  {
    ::min = ::min == -1 ? sel : (::min > sel ? sel : ::min);
    return;
  }
  for (; x <= h; x++)
  {
    for (; y < n; y++)
    {
      if (edge[x][y]) continue;
      edge[x][y] = true;
      dfs(x, y, sel + 1);
      edge[x][y] = false;
    }
    y = 0;
  }
}

bool isValid()
{
  int line;
  for (int i = 1; i <= n; i++)
  {
    line = i;
    for (int j = 1; j <= h; j++)
    {
      if (edge[j][line])
        line++;
      else if (edge[j][line - 1])
        line--;
    }
    if (line != i)
      return false;
  }
  return true;
}