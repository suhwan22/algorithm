#include <iostream>
#include <queue>

using namespace std;

int board[1500][1500] = {};
bool vis[1500][1500] = {};

void printBoard(int r, int c);

struct PPair
{
  int x;
  int y;
  int pre;
  int step;
};

class Comp
{
  public:
    bool operator() (PPair a, PPair b)
    {
      if (a.step > b.step)
        return true;
      if (a.step == b.step)
      {
        if (board[a.x][a.y] > board[b.x][b.y])
          return true;
      }
      return false;
    }
};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int r, c;
  cin >> r >> c;
  string input;
  int cnt = 0;
  pair<int, int> swan[2];
  for (int i = 0; i < r; i++)
  {
    cin >> input;
    for (int j = 0; j < c; j++)
    {
      if (input[j] == '.')
        board[i][j] = 0;
      else if (input[j] == 'X')
        board[i][j] = -1;
      else if (input[j] == 'L')
      {
        swan[cnt].first = i;
        swan[cnt++].second = j;
        board[i][j] = 0;
      }
    }
  }

  int swanNum[2];
  queue<pair<int, int>> q;
  priority_queue<PPair, vector<PPair>, Comp> pq;
  pair<int, int> cur;
  PPair temp;
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  int nx, ny;
  cnt = -1;
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      if (board[i][j] != -1 && vis[i][j] == false)
      {
        vis[i][j] = true;
        cnt++;
        board[i][j] = cnt;
        q.push({i, j});
        temp.x = i;
        temp.y = j;
        temp.step = 0;
        temp.pre = cnt;
        pq.push(temp);
        while (!q.empty())
        {
          cur = q.front();
          q.pop();
          for (int i = 0; i < 2; i++)
          {
            if (swan[i].first == cur.first && swan[i].second == cur.second)
              swanNum[i] = cnt;
          }
          for (int i = 0; i < 4; i++)
          {
            nx = cur.first + dx[i];
            ny = cur.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            if (vis[nx][ny] || board[nx][ny] == -1) continue;
            vis[nx][ny] = true;
            board[nx][ny] = cnt;
            q.push({nx, ny});
            temp.x = nx;
            temp.y = ny;
            temp.step = 0;
            temp.pre = cnt;
            pq.push(temp);
          }
        }
      }
    }
  }
  // printBoard(r, c);
  // cout << swanNum[0] << " " << swanNum[1] << "\n";
  if (swanNum[0] == swanNum[1])
  {
    cout << 0;
    return 0;
  }

  // PPair pcur;
  while (!pq.empty())
  {
    cout << pq.top().pre << "\n";
    pq.pop();
  }
  // while (!pq.empty())
  // {
  //   pcur = pq.top();
  //   pq.pop();
  //   if (pcur.pre != board[pcur.x][pcur.y]) continue;
  //   for (int i = 0; i < 4; i++)
  //   {
  //     nx = pcur.x + dx[i];
  //     ny = pcur.y + dy[i];
  //     if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
  //     if (vis[nx][ny]) continue;

  //   }
  // }

  return 0;
}

void printBoard(int r, int c)
{
  cout << "-------------------\n";
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
      cout << board[i][j] << "   ";
    cout << "\n";
  }
  cout << "-------------------\n";
}