#include <iostream>

using namespace std;

int board[1025][1025] = {};

long long calSum(int x1, int y1, int x2, int y2);

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  int input;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cin >> input;
      board[i][j] = board[i][j - 1] + input;
    }
  }

  int x1, y1, x2, y2;
  while (m--)
  {
    cin >> x1 >> y1 >> x2 >> y2;
    cout << calSum(x1, y1, x2, y2) << "\n";
  }

  return 0;
}

long long calSum(int x1, int y1, int x2, int y2)
{
  long long sum = 0;
  for (int i = x1; i <= x2; i++)
    sum += (board[i][y2] - board[i][y1 - 1]);
  return sum;
}