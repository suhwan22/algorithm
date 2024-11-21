#include <iostream>
#include <queue>

#define INF 2147483647

using namespace std;

// 아기 상어 위치
pair<int, int> shark;
int sharkSize = 2;
int biteCnt = 0;

int board[20][20] = {};
int n;
int nx, ny;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};


class Fish
{
  public:
    int x;
    int y;
    int dis;
    Fish(int a, int b) : x(a), y(b) {};
    Fish() {};
    void calDistance()
    {
      if (board[x][y] >= sharkSize || board[x][y] == 0)
      {
        dis = INF;
        return ;
      }
      queue<pair<int, int>> q;
      pair<int, int> cur;
      int depth = 1;
      bool visit[20][20] = {};
      visit[shark.first][shark.second] = true;
      q.push({shark.first, shark.second});
      q.push({-1, -1});
      while (!q.empty())
      {
        cur = q.front();
        q.pop();
        if (cur.first < 0)
        {
          if (q.empty())
            break;
          q.push({-1, -1});
          depth++;
          continue;
        }
        for (int i = 0; i < 4; i++)
        {
          nx = cur.first + dx[i];
          ny = cur.second + dy[i];
          if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
          if (visit[nx][ny] || board[nx][ny] > sharkSize) continue;
          if (nx == this->x && ny == this->y)
          {
            this->dis = depth;
            return ;
          }
          visit[nx][ny] = true;
          q.push({nx, ny});
        }
      }
    }
    class Comp
    {
      public:
        bool operator() (const Fish &a, const Fish &b) const
        {
          if (a.dis != b.dis)
            return a.dis > b.dis;
          if (a.x != b.x)
            return a.x > b.x;
          return a.y > b.y;
        }
    };
};

// 물고기들
vector<Fish> fishes;


bool sharkMove(const Fish &fish);

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) 
  {
    for (int j = 0; j < n; j++)
    {
      cin >> board[i][j];
      if (board[i][j] == 9)
      {
        shark = {i, j};
        board[i][j] = 0;
      }
      else if (board[i][j] != 0)
        fishes.push_back(Fish(i, j));
    }
  }
  int cnt = 0;
  while (1)
  {
    if (fishes.empty())
      break;
    for (int i = 0; i < (int)fishes.size(); i++)
      fishes[i].calDistance();
    priority_queue<Fish, vector<Fish>, Fish::Comp> q;
    for (auto fish : fishes)
      q.push(fish);
    if (!sharkMove(q.top()))
      break ;
    cnt++;
  }
  cout << cnt;

  return 0;
}

bool sharkMove(const Fish &fish)
{
  if (fish.dis == INF)
    return false;
  queue<pair<int, int>> q;
  pair<int, int> cur;
  bool visit[20][20] = {};
  pair<int, int> before[20][20] = {};
  visit[shark.first][shark.second] = true;
  q.push({shark.first, shark.second});
  while (!q.empty())
  {
    cur = q.front();
    if (cur.first == fish.x && cur.second == fish.y)
    {
      pair<int, int> be = cur;
      while (before[be.first][be.second].first != shark.first 
        || before[be.first][be.second].second != shark.second)
        be = before[be.first][be.second];
      if (board[be.first][be.second] != 0 && board[be.first][be.second] < sharkSize)
      {
        board[be.first][be.second] = 0;
        biteCnt++;
        if (sharkSize == biteCnt)
        {
          sharkSize++;
          biteCnt = 0;
        }
      }
      shark.first = be.first;
      shark.second = be.second;
      return true;
    }
    q.pop();
    for (int i = 0; i < 4; i++)
    {
      nx = cur.first + dx[i];
      ny = cur.second + dy[i];
      if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
      if (visit[nx][ny] || board[nx][ny] > sharkSize) continue;
      visit[nx][ny] = true;
      before[nx][ny] = {cur.first, cur.second};
      q.push({nx, ny});
    }
  }
  return false;
}