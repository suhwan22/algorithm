#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

char board[5][5] = {};
int cnt = 0;
int yCnt = 0;
bool sel[5][5] = {};
int seq[25] = {};
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void printSel();
int bfs();

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string input;
  for (int i = 0; i < 5; i++)
  {
    cin >> input;
    for (int j = 0; j < 5; j++)
    {
      board[i][j] = input[j];
      seq[i * 5 + j] = 1;
    }
  }
  for (int i = 0; i < 7; i++)
    seq[i] = 0;

  do
  {
    for (int i = 0; i < 25; i++)
    {
      if (seq[i] == 0)
        sel[i / 5][i % 5] = true;
    }
    yCnt = 0;
    if (bfs() == 7 && yCnt < 4)
      cnt++;
    for (int i = 0; i < 25; i++)
    {
      if (seq[i] == 0)
        sel[i / 5][i % 5] = false;
    }
  } while (next_permutation(seq, seq + 25));

  cout << cnt;

  return 0;
}

int bfs()
{
  queue<pair<int, int>> q;
  pair<int, int> cur;
  bool visit[5][5] = {};
  int nx, ny;
  int cnt = 0;
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      if (sel[i][j] == true)
      {
        visit[i][j] = true;
        if (board[i][j] == 'Y')
          yCnt++;
        cnt = 1;
        q.push({i, j});
        while (!q.empty())
        {
          cur = q.front();
          q.pop();
          for (int i = 0; i < 4; i++)
          {
            nx = cur.first + dx[i];
            ny = cur.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
            if (sel[nx][ny] == false || visit[nx][ny]) continue;
            visit[nx][ny] = true;
            if (board[nx][ny] == 'Y')
              yCnt++;
            cnt++;
            q.push({nx, ny});
          }
        }
        return cnt;
      }
    }
  }
  return cnt;
}

void printSel()
{
  cout << "----------\n";
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
      cout << sel[i][j] << " ";
    cout << "\n";
  }
  cout << "----------\n";
}