#include <iostream>
#include <cmath>

using namespace std;

int n, l;
int board[100][100] = {};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> l;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cin >> board[i][j];
  }

  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    bool ramp[100] = {};
    bool flag = true;
    int cur = board[i][0];
    for (int j = 0; j < n && flag; j++)
    {
      if (abs(cur - board[i][j]) > 1)
      {
        flag = false;
        break;
      }
      else if (cur < board[i][j])
      {
        for (int k = 1; k <= l; k++)
        {
          if (j - k < 0 || board[i][j - k] != cur || ramp[j - k])
          {
            flag = false;
            break;
          }
          ramp[j - k] = true;
        }
      }
      else if (cur > board[i][j])
      {
        for (int k = 0; k < l; k++)
        {
          if (j + k >= n || board[i][j + k] != cur - 1)
          {
            flag = false;
            break;
          }
          ramp[j + k] = true;
        }
        j += l - 1;
      }
      cur = board[i][j];
    }
    if (flag)
      cnt++;
  }

  for (int i = 0; i < n; i++)
  {
    bool ramp[100] = {};
    bool flag = true;
    int cur = board[0][i];
    for (int j = 0; j < n && flag; j++)
    {
      if (abs(cur - board[j][i]) > 1)
      {
        flag = false;
        break;
      }
      else if (cur < board[j][i])
      {
        for (int k = 1; k <= l; k++)
        {
          if (j - k < 0 || board[j - k][i] != cur || ramp[j - k])
          {
            flag = false;
            break;
          }
          ramp[j - k] = true;
        }
      }
      else if (cur > board[j][i])
      {
        for (int k = 0; k < l; k++)
        {
          if (j + k >= n || board[j + k][i] != cur - 1)
          {
            flag = false;
            break;
          }
          ramp[j + k] = true;
        }
        j += l - 1;
      }
      cur = board[j][i];
    }
    if (flag)
      cnt++;
  }

  cout << cnt;

  return 0;
}