#include <iostream>
#include <queue>

using namespace std;

int board[1500][1500] = {};
int r, c;
int cnt = 0;
pair<int, int> swan[2];
queue<pair<int, int>> sq;
bool swanVisit[1500][1500] = {};
bool swanNum[1500000] = {};

bool swanBFS();
void printBoard();

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> r >> c;
  string input;
  int cnt = 0;
  queue<pair<int, int>> q;
  queue<pair<int, int>> q2;
  q2.push({-1, -1});
  bool visit[1500][1500] = {};
  
  for (int i = 0; i < r; i++)
  {
    cin >> input;
    for (int j = 0; j < c; j++)
    {
      if (input[j] == 'X')
        board[i][j] = -1;
      else
      {
        board[i][j] = 0;
        q2.push({i, j});
        if (input[j] == 'L')
        {
          swan[cnt].first = i;
          swan[cnt++].second = j;
        }
      }
    }
  }

  cnt = -1;
  pair<int, int> cur;
  int nx, ny;
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};

  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      if (visit[i][j] == false && board[i][j] != -1)
      {
        cnt++;
        visit[i][j] = true;
        board[i][j] = cnt;
        q.push({i, j});
        while (!q.empty())
        {
          cur = q.front();
          q.pop();
          if (cur.first == swan[0].first && cur.second == swan[0].second)
            swanNum[cnt] = true;
          for (int i = 0; i < 4; i++)
          {
            nx = cur.first + dx[i];
            ny = cur.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            if (visit[nx][ny] || board[nx][ny] == -1) continue;
            board[nx][ny] = cnt;
            visit[nx][ny] = true;
            q.push({nx, ny});
          }
        }
      }
    }
  }

  sq.push({swan[0].first, swan[0].second});
  swanVisit[swan[0].first][swan[0].second] = true;

  cnt = 0;
  while (!q2.empty())
  {
    cur = q2.front();
    q2.pop();
    if (cur.first == -1)
    {
      // printBoard();
      if (swanBFS())
        break;
      q2.push({-1, -1});
      cnt++;
    }
    else
    {
      for (int i = 0; i < 4; i++)
      {
        nx = cur.first + dx[i];
        ny = cur.second + dy[i];
        if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
        if (swanNum[board[cur.first][cur.second]])
          sq.push({nx, ny});
        if (visit[nx][ny]) continue;
        board[nx][ny] = board[cur.first][cur.second];
        visit[nx][ny] = true;
        q2.push({nx, ny});
      }
    }
  }

  cout << cnt;

  return 0;
}

bool swanBFS()
{
  pair<int, int> cur;

  int nx, ny;
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};

  while (!sq.empty())
  {
    cur = sq.front();
    sq.pop();
    swanNum[board[cur.first][cur.second]] = true;
    if (cur.first == swan[1].first && cur.second == swan[1].second)
      return true;
    for (int i = 0; i < 4; i++)
    {
      nx = cur.first + dx[i];
      ny = cur.second + dy[i];
      if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
      if (swanVisit[nx][ny] || board[nx][ny] == -1) continue;
      swanVisit[nx][ny] = true;
      sq.push({nx, ny});
    }
  }
  return false;
}

void printBoard()
{
  cout << "---------------------------\n";
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      if (i == swan[0].first && j == swan[0].second)
        cout << 'L';
      else if (i == swan[1].first && j == swan[1].second)
        cout << 'U';
      else
        cout << (board[i][j] == -1 ? 'X' : '.');
    }
    cout << "\n";
  }
  cout << "---------------------------\n";
}