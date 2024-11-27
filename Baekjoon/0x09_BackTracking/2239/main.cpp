#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool v[9][10] = {};
bool h[9][10] = {};
bool sq[9][10] = {};
int board[9][9] = {};
vector<pair<int, int>> arr;

bool finded = false;

void dfs(int n);

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  string input;
  for (int i = 0; i < 9; i++)
  {
    cin >> input;
    for (int j = 0; j < 9; j++)
    {
      board[i][j] = input[j] - '0';
      v[j][input[j] - '0'] = true;
      h[i][input[j] - '0'] = true;
      sq[3 * (i / 3) + j / 3][input[j] - '0'] = true;
      if (input[j] == '0')
        arr.push_back({i, j});
    }
  }

  int x = arr[0].first;
  int y = arr[0].second;
  for (int i = 1; i <= 9; i++)
  {
    if (h[x][i] || v[y][i] || sq[3 * (x / 3) + y / 3][i])
      continue;
    h[x][i] = true;
    v[y][i] = true;
    sq[3 * (x / 3) + y / 3][i] = true;
    board[x][y] = i;
    dfs(1);
    h[x][i] = false;
    v[y][i] = false;
    sq[3 * (x / 3) + y / 3][i] = false;
  }

  return 0;
}

void dfs(int n)
{
  if (finded)
    return;
  if (n == (int)arr.size())
  {
    for (int i = 0; i < 9; i++)
    {
      for (int j = 0; j < 9; j++)
        cout << board[i][j];
      cout << "\n";
    }
    finded = true;
    return;
  }
  int x = arr[n].first;
  int y = arr[n].second;
  for (int i = 1; i <= 9; i++)
  {
    if (h[x][i] || v[y][i] || sq[3 * (x / 3) + y / 3][i])
      continue;
    h[x][i] = true;
    v[y][i] = true;
    sq[3 * (x / 3) + y / 3][i] = true;
    board[x][y] = i;
    dfs(n+1);
    h[x][i] = false;
    v[y][i] = false;
    sq[3 * (x / 3) + y / 3][i] = false;
  }
}