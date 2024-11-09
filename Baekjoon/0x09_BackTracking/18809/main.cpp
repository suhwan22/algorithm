#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>

#define INF 2147483647

using namespace std;

// 최대 경우의 수 4200(10C3 * 7C3) * (2500(bfs경우의 수) + 2500(board초기화)) = 21,000,000 
// 완전 탐색으로 구하기 괜찮다.

int board[50][50] = {};
int n, m, g, r;
vector<pair<int, int>> en;
vector<int> seq;
vector<int> rgSeq;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> g >> r;
  // 2 <= n, m <= 50
  // 1 <= g, r <= 5
  // 배양액을 뿌릴 수 있는 땅의 개수는 항상 r+g <= k <= 10

  int input;
  int enCnt = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> input;
      if (input == 0)
        board[i][j] = INF;
      else if (input == 1)
        board[i][j] = 0;
      else if (input == 2)
      {
        en.push_back({i, j});
        enCnt++;
        board[i][j] = 0;
      }
    }
  }

  sort(en.begin(), en.end());
  for (int i = 0; i < enCnt; i++)
    seq.push_back(i < r + g ? 0 : 1);
  for (int i = 0; i < r + g; i++)
    rgSeq.push_back(i < r ? 0 : 1);

  // 뿌릴 수 있는 땅에서 g, r을 선택한다.
  // bfs 돌려서 꽃의 개수를 센다.
  // max와 비교해서 최대값을 저장한다.
  // 모든 경우에 대해서 반복

  int max = 0;
  int cnt = 0;
  int nx, ny;
  int turn = 1;
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  do
  {
    vector<int> enArr;
    for (int i = 0; i < enCnt; i++)
    {
      if (seq[i] == 0)
        enArr.push_back(i);
    }
    do
    {
      queue<pair<int, int>> q;
      pair<int, int> cur;
      turn = 2;
      for (int i = 0; i < r + g; i++)
      {
        nx = en[enArr[i]].first;
        ny = en[enArr[i]].second;
        if (rgSeq[i] == 0)
          board[nx][ny] = -1; // r
        else
          board[nx][ny] = 1; // g
        q.push({nx, ny});
      }
      q.push({-1, -1});
      cnt = 0;
      while (!q.empty())
      {
        // printBoard();
        cur = q.front();
        q.pop();
        if (cur.first < 0)
        {
          if (q.empty())
            break ;
          turn++;
          q.push({-1, -1});
        }
        if (board[cur.first][cur.second] == -INF)
          continue;
        for (int i = 0; i < 4; i++)
        {
          nx = cur.first + dx[i];
          ny = cur.second + dy[i];
          if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
          if (abs(board[nx][ny]) == INF) continue;
          if (board[nx][ny] == 0)
          {
            board[nx][ny] = board[cur.first][cur.second] < 0 ? -turn : turn;
            q.push({nx, ny});
          }
          else if (board[nx][ny] == (board[cur.first][cur.second] < 0 ? turn : -turn))
          {
            board[nx][ny] = -INF;
            cnt++;
          }
        }
      }
      if (cnt > max)
        max = cnt;

      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < m; j++)
        {
          if (board[i][j] != INF)
            board[i][j] = 0;
        }
      }
    } while (next_permutation(rgSeq.begin(), rgSeq.end()));
    
  } while (next_permutation(seq.begin(), seq.end()));
  
  cout << max;

  return 0;
}