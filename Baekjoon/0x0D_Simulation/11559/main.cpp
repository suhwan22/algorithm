#include <iostream>
#include <queue>

// 12 x 6
using namespace std;

int board[12][6] = {};

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool puyoBomb();
void dropPuyo();
void printBoard();

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  string input;

  for (int i = 0; i < 12; i++)
  {
    cin >> input;
    for (int j = 0; j < (int)input.length(); j++)
    {
      if (input[j] == '.')
        board[i][j] = 0;
      else if (input[j] == 'R')
        board[i][j] = 1;
      else if (input[j] == 'G')
        board[i][j] = 2;
      else if (input[j] == 'B')
        board[i][j] = 3;
      else if (input[j] == 'P')
        board[i][j] = 4;
      else if (input[j] == 'Y')
        board[i][j] = 5;
    }
  }
  printBoard();

  int cnt = 0;
  while (1)
  {
    if(puyoBomb())
      cnt++;
    else
      break;
    printBoard();
  }
  cout << cnt;

  return 0;
}

/**
 * 뿌요가 터지는지 확인 후 터트리기
 * 터트린게 1개라도 있으면 true 반환
 * 하나도 없으면 false 반환
 */
bool puyoBomb()
{
  bool flag = false;
  bool visit[12][6] = {};
  int nx, ny;
  queue<pair<int, int>> q;
  pair<int, int> cur;
  vector<vector<pair<int, int>>> remove;
  int cnt;

  for (int x = 0; x < 12; x++)
  {
    for (int y = 0; y < 6; y++)
    {
      if (visit[x][y] == false && board[x][y] != 0)
      {
        vector<pair<int, int>> del;
        cnt = 1;
        visit[x][y] = true;
        q.push({x, y});
        del.push_back({x, y});
        cout << "del push: x: " << x << ", y: " << y << "\n";
        while (!q.empty())
        {
          cur = q.front();
          q.pop();
          for (int i = 0; i < 4; i++)
          {
            nx = cur.first + dx[i];
            ny = cur.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6) continue;
            if (visit[nx][ny] || board[cur.first][cur.second] != board[nx][ny]) continue;
            visit[nx][ny] = true;
            del.push_back({nx, ny});
            cout << "del push: x: " << nx << ", y: " << ny << "\n";
            cnt++;
            q.push({nx, ny});
          }
        }
        if (cnt >= 4)
        {
          for (int i = 0; i < cnt; i++)
            cout << "(" << del[i].first << ", " << del[i].second << ") ";
          cout << "\n";
          remove.push_back(del);
          flag = true;
        }
      }
    }
  }
  for (int i = 0; i < (int)remove.size(); i++)
  {
    for (int j = 0; j < (int)remove[i].size(); j++)
      board[remove[i][j].first][remove[i][j].second] = 0;
  }
  cout << "beforeDrop\n";
  printBoard();
  dropPuyo();
  cout << "afterDrop\n";
  printBoard();
  return flag;
}

void dropPuyo()
{
  int zero = -1;

  for (int j = 0; j < 6; j++)
  {
    zero = -1;
    for (int i = 11; i >= 0; i--)
    {
      if (board[i][j] == 0)
      {
        if (zero == -1)
          zero = i;
      }
      else
      {
        if (zero != -1)
        {
          board[zero][j] = board[i][j];
          board[i][j] = 0;
          i = zero + 1;
          zero = -1;
        }
      }
    }
  }
}

void printBoard()
{
  cout << "-----------\n";
  for (int i = 0; i < 12; i++)
  {
    for (int j = 0; j < 6; j++)
      cout << board[i][j] << " ";
    cout << "\n";
  }
  cout << "-----------\n";
}