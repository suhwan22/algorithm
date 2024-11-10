#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// 맵의 최대 넓이 8 x 8 == 64
// 64개 중 벽으로 만들 3개를 뽑는 경우
// 64C3 == 41664
// 해당 경우마다 bfs 진행
// 41664 x (64 + a, 변수 초기화 등등) == 약 1000만 이하
// 따라서 완전 탐색을 진행해도 무방
// next_permutation() 사용해서 64C3 구현하고
// 각 경우 마다 visit[][] 생성해서 bfs 진행
// bfs돌 때 마다 개수를 세서 총 빈공간 - 3 - cnt 를 해주는 게 안전구역
// 3은 선택한 벽

int board[8][8] = {};
vector<pair<int, int>> en;
vector<pair<int ,int>> virus;
vector<int> seq;
queue<pair<int, int>> q;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> board[i][j];
      if (board[i][j] == 0)
      {
        en.push_back({i, j});
        seq.push_back(1);
      }
      else if (board[i][j] == 2)
        virus.push_back({i, j});
    }
  }

  sort(en.begin(), en.end());
  seq[0] = 0;
  seq[1] = 0;
  seq[2] = 0;

  pair<int, int> cur;
  int nx, ny;
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  int max = 0;
  do
  {
    vector<int> idx;
    int cnt = 0;
    bool visit[8][8] = {};
    for (int i = 0; i < (int)seq.size(); i++)
    {
      if (seq[i] == 0)
        idx.push_back(i);
    }
    for (int i : idx)
    {
      board[en[i].first][en[i].second] = 1;
    }
    for (pair<int, int> v : virus)
    {
      visit[v.first][v.second] = true;
      q.push(v);
    }
    while (!q.empty())
    {
      cur = q.front();
      q.pop();
      for (int i = 0; i < 4; i++)
      {
        nx = cur.first + dx[i];
        ny = cur.second + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (visit[nx][ny] || board[nx][ny] == 1) continue;
        visit[nx][ny] = true;
        cnt++;
        q.push({nx, ny});
      }
    }
    if (max < (int)en.size() - 3 - cnt)
      max = (int)en.size() - 3 - cnt;
    for (int i : idx)
      board[en[i].first][en[i].second] = 0;
  } while (next_permutation(seq.begin(), seq.end()));

  cout << max;

  return 0;
}