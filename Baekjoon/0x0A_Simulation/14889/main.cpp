#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int n;
int board[20][20] = {};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cin >> board[i][j];
  }

  vector<int> seq;
  for (int i = 0; i < n; i++)
    seq.push_back(i < n / 2 ? 0 : 1);
  
  int min = 2147483647;
  do
  {
    int sum = 0;
    vector<int> a, b;
    for (int i = 0; i < n; i++)
    {
      if (seq[i] == 0)
        a.push_back(i);
      else 
        b.push_back(i);
    }
    for (int i : a)
    {
      for (int j : a)
        sum += board[i][j];
    }
    for (int i : b)
    {
      for (int j : b)
        sum -= board[i][j];
    }
    if (min > abs(sum))
      min = abs(sum);
  } while (next_permutation(seq.begin(), seq.end()));
  
  cout << min;

  return 0;
}