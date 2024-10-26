#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int board[100001] = {};
int pre[100001] = {};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  // 0 <= n, m <= 100,000
  if (n == m)
  {
    cout << 0 << "\n";
    cout << n << "\n";
    return 0;
  }

  queue<int> q;
  int cur, nx;
  int dx[2] = {1, -1};
  q.push(n);
  while (!q.empty())
  {
    cur = q.front();
    q.pop();
    for (int i = 0; i < 2; i++)
    {
      nx = cur + dx[i];
      if (nx < 0 || nx > 100000) continue;
      if (board[nx] != 0 && board[cur] + 1 > board[nx]) continue;
      board[nx] = board[cur] + 1;
      pre[nx] = cur;
      if (nx != m)
        q.push(nx);
    }
    nx = 2 * cur;
    if (nx < 0 || nx > 100000) continue;
    if (board[nx] != 0 && board[cur] + 1 > board[nx]) continue;
    board[nx] = board[cur] + 1;
    pre[nx] = cur;
    if (nx != m)
      q.push(nx);
  }

  cout << board[m] << "\n";
  stack<int> output;
  while(1)
  {
    output.push(m);
    if (m == n)
      break;
    m = pre[m];
  }

  while (!output.empty())
  {
    cout << output.top() << " ";
    output.pop();
  }
  
  return 0;
}