#include <iostream>

using namespace std;

int dx[19][4] = {{0,1,2,3},{0,0,0,0}
                ,{0,0,1,1}
                ,{0,0,0,1},{0,1,1,1},{0,1,2,2},{0,0,1,2}
                ,{0,1,1,1},{0,0,0,1},{0,0,1,2},{0,1,2,2}
                ,{0,1,1,2},{0,0,1,1},{0,0,1,1},{0,1,1,2}
                ,{0,1,1,1},{0,1,1,2},{0,1,1,2},{0,0,0,1}};

int dy[19][4] = {{0,0,0,0},{0,1,2,3}
                ,{0,1,0,1}
                ,{0,1,2,0},{0,-2,-1,0},{0,0,0,1},{0,1,1,1}
                ,{0,0,1,2},{0,1,2,2},{0,1,0,0},{0,0,0,-1}
                ,{0,0,1,1},{0,1,-1,0},{0,1,1,2},{0,-1,0,-1}
                ,{0,-1,0,1},{0,0,1,0},{0,-1,0,0},{0,1,2,1}};

int board[500][500] = {};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
      cin >> board[i][j];
  }

  int nx, ny;
  int max = 0;
  int temp;
  bool flag;
  for (int x = 0; x < n; x++)
  {
    for (int y = 0; y < m; y++)
    {
      for (int i = 0; i < 19; i++)
      {
        temp = 0;
        flag = true;
        for (int j = 0; j < 4; j++)
        {
          nx = x + dx[i][j];
          ny = y + dy[i][j];
          if (nx < 0 || ny < 0 || nx >= n || ny >= m)
          {
            flag = false;
            break;
          }
          temp += board[nx][ny];
        }
        if (flag && max < temp)
          max = temp;
      }
    }
  }

  cout << max;

  return 0;
}