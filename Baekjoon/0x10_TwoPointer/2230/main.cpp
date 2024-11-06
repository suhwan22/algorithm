#include <iostream>
#include <algorithm>

using namespace std;

int board[100000] = {};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> board[i];
  
  sort(board, board + n);
  int st = 0, en = 0;
  int min = 2147483647;
  while (en < n)
  {
    if (board[en] - board[st] >= m)
    {
      if (min > board[en] - board[st])
        min = board[en] - board[st];
      st++;
    }
    else
      en++;
  }

  cout << min;

  return 0;
}