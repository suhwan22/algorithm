#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

pair<int, pair<int, int>> D[1002][1002] = {};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string str1, str2;

  cin >> str1 >> str2;

  string big, small;
  big = str1.length() >= str2.length() ? str1 : str2;
  small = str1.length() >= str2.length() ? str2 : str1;

  int max = 0;
  int x = 0, y = 0;

  for (int i = 0; i < (int)small.length(); i++)
  {
    for (int j = 0; j < (int)big.length(); j++)
    {
      if (big[j] == small[i])
      {
        D[i+1][j+1].first = D[i][j].first + 1;
        D[i+1][j+1].second = {i, j};
        if (max < (int)D[i+1][j+1].first)
        {
          max = D[i+1][j+1].first;
          x = i+1;
          y = j+1;
        }
      }
      else
      {
        if (D[i+1][j].first > D[i][j+1].first)
        {
          D[i+1][j+1].first = D[i+1][j].first;
          D[i+1][j+1].second = D[i+1][j].second;
        }
        else
        {
          D[i+1][j+1].first = D[i][j+1].first;
          D[i+1][j+1].second = D[i][j+1].second;
        }
      }
    }
  }

  cout << max << "\n";
  if (max == 0) return 0;
  vector<char> output;
  pair<int, int> cur;
  cur.first = x;
  cur.second = y;
  for (int i = 0; i < max; i++)
  {
    cur = D[cur.first][cur.second].second;
    output.push_back(big[cur.second]);
  }
  for (int i = output.size() - 1; i >= 0; i--)
    cout << output[i];

  return 0;
}