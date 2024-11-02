#include <iostream>
#include <queue>
#include <cstdlib>

using namespace std;

int n, m, p;

int s[10] = {};
int board[1000][1000] = {};

typedef struct PPair
{
  int x;
  int y;
  int step;
  int turn;
} PPair;

class Comp
{
  public:
    bool operator() (const PPair &a, const PPair &b)
    {
      if (a.turn > b.turn)
        return true;
      else if (a.turn == b.turn)
      {
        if (board[a.x][a.y] > board[b.x][b.y])
          return true;
        else if (board[a.x][a.y] == board[b.x][b.y])
        {
          if (a.step > b.step)
            return true;
        }
      }
      return false;
    }
};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> p;

  int seq;
  for (int i = 1; i <= p; i++)
  {
    cin >> seq;
    if (seq > 1000000)
      s[i] = 1000000;
    else
      s[i] = seq;
  }

  string input;
  for (int i = 0; i < n; i++)
  {
    cin >> input;
    for (int j = 0; j < m; j++)
    {
      if (input[j] == '.')
        board[i][j] = 0;
      else if (input[j] == '#')
        board[i][j] = -1;
      else
        board[i][j] = input[j] - '0';
    }
  }

  priority_queue<PPair, vector<PPair>, Comp> pq = {};
  PPair cur;
  int dx[4] = {-1, 0, 1, 0};
  int dy[4] = {0, 1, 0, -1};
  int nx, ny;
  int output[10] = {};
  bool visit[1000][1000] = {};
  PPair temp;

  int turn = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (board[i][j] > 0)
      {
        visit[i][j] = true;
        output[board[i][j]]++;
        temp.x = i;
        temp.y = j;
        temp.step = 0;
        temp.turn = turn;
        pq.push(temp);
      }
    }
  }

  while (!pq.empty())
  {
    cur = pq.top();
    pq.pop();
    if (cur.step == s[board[cur.x][cur.y]])
    {
      temp.x = cur.x;
      temp.y = cur.y;
      temp.step = 0;
      temp.turn = cur.turn + 1;
      pq.push(temp);
      continue;
    }
    for (int i = 0; i < 4; i++)
    {
      nx = cur.x + dx[i];
      ny = cur.y + dy[i];
      if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
      if (visit[nx][ny] || board[nx][ny] == -1) continue;
      visit[nx][ny] = true;
      board[nx][ny] = board[cur.x][cur.y];
      output[board[nx][ny]]++;
      temp.x = nx;
      temp.y = ny;
      temp.step = cur.step + 1;
      temp.turn = cur.turn;
      pq.push(temp);
    }
  }

  for (int i = 1; i <= p; i++)
    cout << output[i] << " ";

  return 0;
}