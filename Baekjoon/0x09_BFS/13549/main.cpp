#include <iostream>
#include <queue>

using namespace std;

int board[200001] = {};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  bool visit[200001] = {};

  int n, k;
  cin >> n >> k;
  // n -> k
  queue<int> q;
  int cur;
  int nx;
  q.push(n);
  while (!q.empty())
  {
    cur = q.front();
    q.pop();
    if (cur == k) continue;
    nx = cur + 1;
    if (nx >= 0 && nx <= 200000)
    {
      if ((visit[nx] == false && board[nx] == 0) || board[nx] > board[cur] + 1)
      {
        board[nx] = board[cur] + 1;
        q.push(nx);
      }
    }
    nx = cur - 1;
    if (nx >= 0 && nx <= 200000)
    {
      if ((visit[nx] == false && board[nx] == 0) || board[nx] > board[cur] + 1)
      {
        board[nx] = board[cur] + 1;
        q.push(nx);
      }
    }
    nx = 2 * cur;
    if (nx >= 0 && nx <= 200000)
    {
      if ((visit[nx] == false && board[nx] == 0) || board[nx] > board[cur])
      {
        visit[nx] = true;
        board[nx] = board[cur];
        q.push(nx);
      }
    }
  }

  cout << board[k];

  return 0;
}