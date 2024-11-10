#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int board[11] = {};
int n;

vector<int> cmd;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> board[i];

  int m;
  int k = 1;
  for (int i = 0; i < 4; i++)
  {
    cin >> m;
    while (m--)
      cmd.push_back(k);
    k++;
  }

  int min = 2147483647;
  int max = -2147483648;
  do
  {
    int cur = board[0];
    for (int i = 0; i < n - 1; i++)
    {
      if (cmd[i] == 1)
        cur += board[i + 1];
      else if (cmd[i] == 2)
        cur -= board[i + 1];
      else if (cmd[i] == 3)
        cur *= board[i + 1];
      else if (cmd[i] == 4)
        cur /= board[i + 1];
    }
    if (min > cur)
      min = cur;
    if (max < cur)
      max = cur;
  } while (next_permutation(cmd.begin(), cmd.end()));

  cout << max << "\n" << min;
  

  return 0;
}