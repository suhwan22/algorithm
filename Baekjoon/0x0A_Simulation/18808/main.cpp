#include <iostream>
#include <queue>
#include <map>

using namespace std;

class Sticker
{
  public:
    int sticker[10][10];
    int _n;
    int _m;
  public:
    Sticker() {}
    Sticker(int n, int m)
    {
      _n = n;
      _m = m;
      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < m; j++)
          cin >> sticker[i][j];
      }
    }
    ~Sticker() {}

    void rotation()
    {
      int temp[10][10];
      int tmp = _n;
      _n = _m;
      _m = tmp;
      for (int i = 0; i < _n; i++)
      {
        for (int j = 0; j < _m; j++)
          temp[i][j] = sticker[_m - 1 - j][i];
      }
      for (int i = 0; i < _n; i++)
      {
        for (int j = 0; j < _m; j++)
          sticker[i][j] = temp[i][j];
      }
    }

    void show()
    {
      cout << "-------------------\n";
      for (int i = 0; i < _n; i++)
      {
        for (int j = 0; j < _m; j++)
          cout << sticker[i][j] << " ";
        cout << "\n";
      }
      cout << "-------------------\n";
    }
};


bool validPos(int x, int y, int n, int m);
bool validAllRot(int x, int y, int n, int m);
void setSticker(int x, int y);

int board[40][40] = {};
queue<Sticker*> q;

void printBoard(int n, int m)
{
  cout << "===================\n";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
      cout << board[i][j] << " ";
    cout << "\n";
  }
  cout << "===================\n";
}


int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k;
  // 1 <= n: row <= 40, 1 < =m: colunm <= 40, 1 <= k: 스티커 개수 <= 100
  // 스티커당 1 <= r:row <= 10, 1 <= c:column <= 10
  // 0: 은 빈곳, 1: 스티커가 있는 부분

  cin >> n >> m >> k;
  int r, c;

  for (int i = 0; i < k; i++)
  {
    cin >> r >> c;
    Sticker *temp = new Sticker(r, c);
    q.push(temp);
  }
  // while (!q.empty())
  // {
  //   q.front()->show();
  //   q.pop();
  // }

  int count = 0;

  while (!q.empty())
  {
    int size = q.size();
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (validPos(i, j, n, m))
        {
          setSticker(i, j);
          delete q.front();
          q.pop();
          i = n;
          break;
        }
      }
    }
    if (size == (int)q.size())
    {
      if (count == 3)
      {
        delete q.front();
        q.pop();
        count = 0;
        continue;
      }
      q.front()->rotation();
      count++;
    }
    else
    {
      count = 0;
    }
    // printBoard(n, m);
  }

  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (board[i][j] == 1)
        cnt++;
    }
  }
  cout << cnt;

  return 0;
}

bool validPos(int x, int y, int n, int m)
{
  // cout << "[validPos] x: " << x << ", y: " << y << "\n";
  // q.front()->show();
  if (x + q.front()->_n > n || y + q.front()->_m > m)
    return false;
  for (int i = 0; i < q.front()->_n; i++)
  {
    for (int j = 0; j < q.front()->_m; j++)
    {
      if (board[x + i][y + j] == 1 && q.front()->sticker[i][j] == 1)
        return false;
    }
  }
  return true;
}

bool validAllRot(int x, int y, int n, int m)
{
  if (validPos(x, y, n, m))
    return true;
  q.front()->rotation();
  if (validPos(x, y, n, m))
    return true;
  q.front()->rotation();
  if (validPos(x, y, n, m))
    return true;
  q.front()->rotation();
  if (validPos(x, y, n, m))
    return true;
  q.front()->rotation();
  return false;
}

void setSticker(int x, int y)
{
  // cout << "[setSticker] x: " << x << ", y: " << y << "\n";
  // q.front()->show();
  for (int i = 0; i < q.front()->_n; i++)
  {
    for (int j = 0; j < q.front()->_m; j++)
    {
      if (q.front()->sticker[i][j] == 1)
        board[x + i][y + j] = q.front()->sticker[i][j];
    }
  }
}