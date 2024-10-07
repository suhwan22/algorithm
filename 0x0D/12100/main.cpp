#include <iostream>
#include <map>

using namespace std;


int board[20][20] = {};
int max = 0;

void printBoard(int arr[20][20], int narr[20][20], int n, int dir);
void left(int arr[20][20], int n, int cnt);
void right(int arr[20][20], int n, int cnt);
void up(int arr[20][20], int n, int cnt);
void down(int arr[20][20], int n, int cnt);

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cin >> board[i][j];
  }

  left(board, n, 0);
  right(board, n, 0);
  up(board, n, 0);
  down(board, n, 0);

  cout << ::max;

  return 0;
}

// left
void left(int arr[20][20], int n, int cnt)
{
  int b = 0;
  pair<int, int> pos;
  int narr[20][20];
  if (cnt == 5)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
        if (::max < arr[i][j])
          ::max = arr[i][j];
    }
    return ;
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j ++)
      narr[i][j] = arr[i][j];
  }

  /**
   * 왼쪽에서 오른쪽으로 보면서 겹치면 더해주기
   */
  for (int i = 0; i < n; i++)
  {
    b = 0;
    for (int j = 0; j < n; j++)
    {
      if (narr[i][j] != 0)
      {
        if (b == 0)
        {
          b = narr[i][j];
          pos = {i, j};
        }
        else if (b != 0)
        {
          if (narr[i][j] == b)
          {
            narr[pos.first][pos.second] *= 2;
            narr[i][j] = 0;
            b = 0;
          }
          else
          {
            b = narr[i][j];
            pos = {i, j};
          }
        }
      }
    }
  }

  /**
   * 전체를 왼쪽으로 밀기
   */
  for (int i = 0; i < n; i++)
  {
    b = 0;
    for (int j = 0; j < n; j++)
    {
      if (narr[i][j] == 0)
      {
        if (b == 0)
        {
          pos = {i, j};
          b = 1;
        }
      }
      else
      {
        if (b != 0)
        {
          narr[pos.first][pos.second] = narr[i][j];
          narr[i][j] = 0;
          b = 0;
          j = pos.second - 1;
        }
      }
    }
  }
  // printBoard(arr, narr, n, 0);
  left(narr, n, cnt + 1);
  right(narr, n, cnt + 1);
  up(narr, n, cnt + 1);
  down(narr, n, cnt + 1);
}

// right
void right(int arr[20][20], int n, int cnt)
{
  int b = 0;
  pair<int, int> pos;
  int narr[20][20];
  if (cnt == 5)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
        if (::max < arr[i][j])
          ::max = arr[i][j];
    }
    return ;
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j ++)
      narr[i][j] = arr[i][j];
  }

  /**
   * 오른쪽에서 왼쪽으로 보면서 겹치면 더해주기
   */
  for (int i = 0; i < n; i++)
  {
    b = 0;
    for (int j = n - 1; j >= 0; j--)
    {
      if (narr[i][j] != 0)
      {
        if (b == 0)
        {
          b = narr[i][j];
          pos = {i, j};
        }
        else if (b != 0)
        {
          if (narr[i][j] == b)
          {
            narr[pos.first][pos.second] *= 2;
            narr[i][j] = 0;
            b = 0;
          }
          else
          {
            b = narr[i][j];
            pos = {i, j};
          }
        }
      }
    }
  }

  /**
   * 전체를 오른쪽으로 밀기
   */
  for (int i = 0; i < n; i++)
  {
    b = 0;
    for (int j = n - 1; j >= 0; j--)
    {
      if (narr[i][j] == 0)
      {
        if (b == 0)
        {
          pos = {i, j};
          b = 1;
        }
      }
      else
      {
        if (b != 0)
        {
          narr[pos.first][pos.second] = narr[i][j];
          narr[i][j] = 0;
          b = 0;
          j = pos.second + 1;
        }
      }
    }
  }
  // printBoard(arr, narr, n, 1);
  left(narr, n, cnt + 1);
  right(narr, n, cnt + 1);
  up(narr, n, cnt + 1);
  down(narr, n, cnt + 1);
}

// up
void up(int arr[20][20], int n, int cnt)
{
  int b = 0;
  pair<int, int> pos;
  int narr[20][20];
  if (cnt == 5)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
        if (::max < arr[i][j])
          ::max = arr[i][j];
    }
    return ;
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j ++)
      narr[i][j] = arr[i][j];
  }

  /**
   * 위쪽에서 아래로 보면서 겹치면 더해주기
   */
  for (int i = 0; i < n; i++)
  {
    b = 0;
    for (int j = 0; j < n; j++)
    {
      if (narr[j][i] != 0)
      {
        if (b == 0)
        {
          b = narr[j][i];
          pos = {j, i};
        }
        else if (b != 0)
        {
          if (narr[j][i] == b)
          {
            narr[pos.first][pos.second] *= 2;
            narr[j][i] = 0;
            b = 0;
          }
          else
          {
            b = narr[j][i];
            pos = {j, i};
          }
        }
      }
    }
  }

  /**
   * 전체를 위쪽으로 밀기
   */
  for (int i = 0; i < n; i++)
  {
    b = 0;
    for (int j = 0; j < n; j++)
    {
      if (narr[j][i] == 0)
      {
        if (b == 0)
        {
          pos = {j, i};
          b = 1;
        }
      }
      else
      {
        if (b != 0)
        {
          narr[pos.first][pos.second] = narr[j][i];
          narr[j][i] = 0;
          b = 0;
          j = pos.first - 1;
        }
      }
    }
  }
  // printBoard(arr, narr, n, 2);
  left(narr, n, cnt + 1);
  right(narr, n, cnt + 1);
  up(narr, n, cnt + 1);
  down(narr, n, cnt + 1);
}

// down
void down(int arr[20][20], int n, int cnt)
{
  int b = 0;
  pair<int, int> pos;
  int narr[20][20];
  if (cnt == 5)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
        if (::max < arr[i][j])
          ::max = arr[i][j];
    }
    return ;
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j ++)
      narr[i][j] = arr[i][j];
  }

  /**
   *  아래에서 위로 보면서 겹치면 더해주기
   */
  for (int i = 0; i < n; i++)
  {
    b = 0;
    for (int j = n - 1; j >= 0; j--)
    {
      if (narr[j][i] != 0)
      {
        if (b == 0)
        {
          b = narr[j][i];
          pos = {j, i};
        }
        else if (b != 0)
        {
          if (narr[j][i] == b)
          {
            narr[pos.first][pos.second] *= 2;
            narr[j][i] = 0;
            b = 0;
          }
          else
          {
            b = narr[j][i];
            pos = {j, i};
          }
        }
      }
    }
  }

  /**
   * 전체를 아래쪽으로 밀기
   */
  for (int i = 0; i < n; i++)
  {
    b = 0;
    for (int j = n - 1; j >= 0; j--)
    {
      if (narr[j][i] == 0)
      {
        if (b == 0)
        {
          pos = {j, i};
          b = 1;
        }
      }
      else
      {
        if (b != 0)
        {
          narr[pos.first][pos.second] = narr[j][i];
          narr[j][i] = 0;
          b = 0;
          j = pos.first + 1;
        }
      }
    }
  }
  // printBoard(arr, narr, n, 3);
  left(narr, n, cnt + 1);
  right(narr, n, cnt + 1);
  up(narr, n, cnt + 1);
  down(narr, n, cnt + 1);
}

void printBoard(int arr[20][20], int narr[20][20], int n, int dir)
{
  if (dir == 0)
  {
    cout << "-----[left.before]-----\n";
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
        cout << arr[i][j] << " ";
      cout << "\n";
    }
    cout << "-----[left.after]-----\n";
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
        cout << narr[i][j] << " ";
      cout << "\n";
    }
    cout << "----------------------\n";
  }
  else if (dir == 1)
  {
    cout << "-----[right.before]-----\n";
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
        cout << arr[i][j] << " ";
      cout << "\n";
    }
    cout << "-----[right.after]-----\n";
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
        cout << narr[i][j] << " ";
      cout << "\n";
    }
    cout << "----------------------\n";
  }
  else if (dir == 2)
  {
    cout << "-----[up.before]-----\n";
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
        cout << arr[i][j] << " ";
      cout << "\n";
    }
    cout << "-----[up.after]-----\n";
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
        cout << narr[i][j] << " ";
      cout << "\n";
    }
    cout << "----------------------\n";
  }
  else if (dir == 3)
  {
    cout << "-----[down.before]-----\n";
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
        cout << arr[i][j] << " ";
      cout << "\n";
    }
    cout << "-----[down.after]-----\n";
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
        cout << narr[i][j] << " ";
      cout << "\n";
    }
    cout << "----------------------\n";
  }
}