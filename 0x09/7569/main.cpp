#include <iostream>
#include <queue>
#include <map>

using namespace std;

class Trio
{
  public:
    int x;
    int y;
    int z;
    Trio() {}
    Trio(int a, int b, int c): x(a), y(b), z(c) {}
};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, h;
  cin >> m >> n >> h;
  int board[100][100][100];
  bool v[100][100][100] = {};
  int dx[6] = {0, -1, 0, 1, 0, 0};
  int dy[6] = {1, 0, -1, 0, 0, 0};
  int dz[6] = {0, 0, 0, 0, 1, -1};

  queue<Trio> q;
  Trio cur;
  int nx, ny, nz;


  for (int z = 0; z < h; z++)
  {
    for (int x = 0; x < n; x++)
    {
      for (int y = 0; y < m; y++)
      {
        cin >> board[x][y][z];
        if (board[x][y][z] == 1)
        {
          v[x][y][z] = true;
          q.push(Trio(x, y, z));
        }
      }
    }
  }

  while (!q.empty())
  {
    cur = q.front();
    q.pop();
    for (int i = 0; i < 6; i++)
    {
      nx = cur.x + dx[i];
      ny = cur.y + dy[i];
      nz = cur.z + dz[i];
      if (nx < 0 || ny < 0 || nx >= n || ny >= m || nz < 0 || nz >= h) continue;
      if (v[nx][ny][nz] == true || board[nx][ny][nz] < 0) continue;
      v[nx][ny][nz] = true;
      board[nx][ny][nz] = board[cur.x][cur.y][cur.z] + 1;
      q.push(Trio(nx, ny, nz));
    }
  }

  int max = 0;
  for (int x = 0; x < n; x++)
  {
    for (int y = 0; y < m; y++)
    {
      for (int z = 0; z < h; z++)
      {
        if (board[x][y][z] == 0)
        {
          cout << -1;
          return 0;
        }
        else if (max < board[x][y][z])
          max = board[x][y][z];
      }
    }
  }

  cout << max - 1;


  return 0;
}