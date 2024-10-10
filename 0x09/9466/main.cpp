#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int board[100001]={};
int v[100001]={};
bool s[100001]={};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t, n;
  cin >> t;
  int cur;
  int nx;
  while (t--)
  {
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
      cin >> board[i];
      if (board[i] == i)
        s[i] = true;
    }
    for (int i = 1; i <= n; i++)
    {
      if (v[i] == 0 && s[i] == false)
      {
        v[i] = i;
        cur = i;
        while (1)
        {
          nx = board[cur];
          if (s[nx] || (v[nx] != 0 && v[nx] != i))
            break;
          if (nx == board[nx])
          {
            s[nx] = true;
            break;
          }
          if (v[nx] == i)
          {
            s[nx] = true;
            for (int k = board[nx]; k != nx; k = board[k])
              s[k] = true;
            break;
          }
          v[nx] = i;
          cur = nx;
        }
      }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
      if (s[i] == false)
        cnt++;
    }
    cout << cnt << "\n";
    bzero(s, sizeof(s));
    bzero(v, sizeof(v));
  }

  return 0;
}