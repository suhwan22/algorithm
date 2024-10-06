#include <iostream>
#include <cmath>

using namespace std;

int board[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
bool queen[15] = {};
int cnt = 0;

// board[i] == j, (i, j);
// board[i + 1] == k, (i + 1, k);
// idx 는 row, 들어 있는 값은 column 값
// 0~n 의 값을 board[i]에 넣는 건데
// 대각으로 안겹쳐야 한다.
// 대각 확인은 두 좌표의 기울기가 1, -1 인지 보면 될듯?
// queen[] 은 사용한 queen 체크용, 안쓰고 그때그때 판단해도 됨 board[i] == board[j] 로

void printBoard(int n)
{
  cout << "---------------\n";
  cout << "queen used: ";
  for (int i = 0; i < n; i++)
  {
    if (queen[i])
      cout << i << " ";
  }
  cout << "\n";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (board[i] != j)
        cout << "O";
      else
        cout << "*";
    }
    cout << "\n";
  }
  cout << "---------------\n";
}


void nQueen(int n, int m)
{
  for (int i = 0; i < m - 1; i++)
  {
    if ((m - 1) - i == abs(board[(m - 1)] - board[i]))
      return;
  }
  if (m == n)
  {
    cnt++;
    return ;
  }
  for (int i = 0; i < n; i++)
  {
    if (queen[i] == false)
    {
      board[m] = i;
      queen[i] = true;
      // printBoard(n);
      nQueen(n, m + 1);
      queen[i] = false;
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  nQueen(n, 0);
  cout << cnt;

  return 0;
}