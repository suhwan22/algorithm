#include <iostream>

using namespace std;

int board[1000] = {};
int D[1000] = {};
int n;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  int max = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> board[i];
    D[i] = board[i];
    for (int j = 0; j < i; j++)
      D[i] = board[j] < board[i] ? (D[j] + board[i] > D[i] ? D[j] + board[i] : D[i]) : D[i];
    max = D[i] > max ? D[i] : max;
  }
  
  cout << max;

  return 0;
}