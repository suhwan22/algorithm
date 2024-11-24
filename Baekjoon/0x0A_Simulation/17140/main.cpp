#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int board[101][101] = {};
int r, c, k;

int R(int row, int col);
int C(int row, int col);

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> r >> c >> k;
  for (int i = 1; i <= 3; i++)
  {
    for (int j = 1; j <= 3; j++)
      cin >> board[i][j];
  }

  int time = 0;
  int row = 3, col = 3;
  while (1)
  {
    if (board[r][c] == k || time >= 100)
      break;
    if (row >= col)
      col = R(row, col);
    else
      row = C(row, col);
    time++;
  }

  if (board[r][c] == k)
    cout << time;
  else
    cout << -1;

  return 0;
}

int R(int row, int col)
{
  int colMax = 0;
  int colArr[101] = {};
  for (int i = 1; i <= row; i++)
  {
    pair<int, int> arr[101] = {};
    int j = 1;
    for (; j <= col; j++)
    {
      if (board[i][j] == 0) continue;
      arr[board[i][j]].second = board[i][j];
      arr[board[i][j]].first++;
    }
    sort(arr, arr + 101);
    int y = 0;
    while (arr[y].first == 0) y++;
    j = 1;
    for (;y <= 100; y++)
    {
      board[i][j++] = arr[y].second;
      board[i][j++] = arr[y].first;
    }
    colArr[i] = j - 1;
    if (colMax < j - 1)
      colMax = j - 1;
  }
  for (int i = 1; i <= row; i++)
  {
    for (int j = colMax; j > colArr[i]; j--)
      board[i][j] = 0;
  }
  return colMax;
}

int C(int row, int col)
{
  int rowMax = 0;
  int rowArr[101] = {};
  for (int i = 1; i <= col; i++)
  {
    pair<int, int> arr[101] = {};
    int j = 1;
    for (; j <= row; j++)
    {
      if (board[j][i] == 0) continue;
      arr[board[j][i]].second = board[j][i];
      arr[board[j][i]].first++;
    }
    sort(arr, arr + 101);
    int x = 0;
    while (arr[x].first == 0) x++;
    j = 1;
    for (;x <= 100; x++)
    {
      board[j++][i] = arr[x].second;
      board[j++][i] = arr[x].first;
    }
    rowArr[i] = j - 1;
    if (rowMax < j - 1)
      rowMax = j - 1;
  }
  for (int i = 1; i <= col; i++)
  {
    for (int j = rowMax; j > rowArr[i]; j--)
      board[j][i] = 0;
  }
  return rowMax;
}