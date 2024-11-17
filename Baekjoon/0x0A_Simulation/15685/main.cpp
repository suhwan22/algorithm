#include <iostream>
#include <vector>

using namespace std;

bool board[101][101] = {};
vector<pair<int, int>> dragonArr[20] = {};

void dragonCurve(vector<pair<int, int>> &dragon, int n, int cnt);

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  pair<int, int> p;
  int dir;
  int k;
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, -1, 0, 1};
  for (int i = 0; i < n; i++)
  {
    cin >> p.first >> p.second >> dir >> k;
    dragonArr[i].push_back(p);
    board[p.first][p.second] = true;
    p.first = p.first + dx[dir];
    p.second = p.second + dy[dir];
    dragonArr[i].push_back(p);
    board[p.first][p.second] = true;
    dragonCurve(dragonArr[i], k, 0);
  }

  int cnt = 0;
  for (int i = 0; i < 100; i++)
  {
    for (int j = 0; j < 100; j++)
    {
      if (board[i][j] && board[i+1][j] && board[i+1][j+1] && board[i][j+1])
        cnt++;
    }
  }
  cout << cnt;

  return 0;
}

void dragonCurve(vector<pair<int, int>> &dragon, int n, int cnt)
{
  if (cnt >= n)
    return;
  pair<int, int> last = dragon.back();
  pair<int, int> nd;
  for (int i = dragon.size() - 2; i >= 0; i--)
  {
    nd.first = last.first - (dragon[i].second - last.second);
    nd.second = last.second + dragon[i].first - last.first;
    if (nd.first >= 0 && nd.first <= 100 && nd.second >= 0 && nd.second <= 100)
      board[nd.first][nd.second] = true;
    dragon.push_back(nd);
  }
  dragonCurve(dragon, n, cnt + 1);
}