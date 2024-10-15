#include <iostream>
#include <queue>

using namespace std;

int board[100001] = {};

int main()
{
  int n, m;
  cin >> n >> m;
  // n 수빈 위치, m 동생 위치
  // n -> m 

  if (n == m)
  {
    cout << 0 << "\n" << 1;
    return 0;
  }

  queue<pair<int, int>> q;
  pair<int, int> cur;
  // {x, step}

  int nx;
  int dx[2] = {-1, 1};
  int min = 2147483647;
  int cnt = 0;

  q.push({n, 0});
  while (!q.empty())
  {
    cur = q.front();
    q.pop();
    for (int i = 0; i < 2; i++) 
    {
      nx = cur.first + dx[i];
      if (nx < 0 || nx > 100000) continue;
      if (nx == m)
      {
        if (min > cur.second + 1)
        {
          min = cur.second + 1;
          cnt = 1;
        }
        else if (min == cur.second + 1)
          cnt++; 
      }
      else
      {
        if (min < cur.second + 1 || (board[nx] != 0 && board[nx] < cur.second + 1)) continue;
        board[nx] = cur.second + 1;
        q.push({nx, cur.second + 1});
      }
    }
    nx = 2 * cur.first;
    if (nx < 0 || nx > 100000) continue;
    if (nx == m)
    {
      if (min > cur.second + 1)
      {
        min = cur.second + 1;
        cnt = 1;
      }
      else if (min == cur.second + 1)
        cnt++;
    }
    else
    {
      if (min < cur.second + 1 || (board[nx] != 0 && board[nx] < cur.second + 1)) continue;
      board[nx] = cur.second + 1;
      q.push({nx, cur.second + 1});
    }
  }

  cout << min << "\n" << cnt;
}