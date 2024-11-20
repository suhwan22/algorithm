#include <iostream>
#include <vector>

using namespace std;

int board[1000] = {};
vector<int> D[1000] = {};
int n;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> board[i];

  int index = 0;
  D[0].push_back(board[0]);
  for (int i = 1; i < n; i++)
  {
    int idx = -1, max = 0;
    for (int j = 0; j < i; j++)
    {
      if (board[j] >= board[i]) continue;
      if (max < (int)D[j].size())
      {
        max = D[j].size();
        idx = j;
      }
    }
    if (idx != -1)
    {
      for (auto e : D[idx])
        D[i].push_back(e);
    }
    D[i].push_back(board[i]);
    if (D[index].size() < D[i].size())
      index = i;
  }

  cout << D[index].size() << "\n";
  for (auto e : D[index])
    cout << e << " ";

  return 0;
}