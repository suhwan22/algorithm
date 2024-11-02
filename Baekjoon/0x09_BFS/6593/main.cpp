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
    void set(int a, int b, int c)
    {
      x = a;
      y = b;
      z = c;
    }
};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int l, r, c;
  // 1 <= l: 층, r: 행, c: 열 <= 30
  int board[30][30][30]; // board[x][y][z]
  int dx[6] = {0, -1, 0, 1, 0, 0};
  int dy[6] = {1, 0, -1, 0, 0, 0};
  int dz[6] = {0, 0, 0, 0, 1, -1};

  string input;
  Trio start;

  while (1)
  {
    cin >> l >> r >> c;
    if (l == 0 || r == 0 || c == 0)
      break;
    for (int i = 0; i < l; i++)
    {
      for (int j = 0; j < r; j++)
      {
        cin >> input;
        for (int k = 0; k < c; k++)
        {
          if (input.at(k) == 'S')
          {
            start.set(j, k, i);
            board[j][k][i] = 1;
          }
          else if (input.at(k) == '.')
            board[j][k][i] = 0;
          else if (input.at(k) == '#')
            board[j][k][i] = -1;
          else
            board[j][k][i] = -2;
        }
      }
    }
    queue<Trio> q;
    Trio cur;
    int nx, ny, nz;
    bool flag = false;
    q.push(start);
    while (!q.empty())
    {
      cur = q.front();
      q.pop();
      for (int i = 0; i < 6; i++)
      {
        nx = cur.x + dx[i];
        ny = cur.y + dy[i];
        nz = cur.z + dz[i];
        if (nx < 0 || ny < 0 || nz < 0 || nx >= r || ny >= c || nz >= l) continue;
        if (board[nx][ny][nz] == -1 || board[nx][ny][nz] > 0) continue;
        if (board[nx][ny][nz] == -2)
        {
          cout << "Escaped in " << board[cur.x][cur.y][cur.z] << " minute(s).\n";
          flag = true;
          q = queue<Trio>();
          break;
        }
        board[nx][ny][nz] = board[cur.x][cur.y][cur.z] + 1;
        q.push(Trio(nx, ny, nz));
      }
    }
    if (!flag)
      cout << "Trapped!\n";
  }

  return 0;
}