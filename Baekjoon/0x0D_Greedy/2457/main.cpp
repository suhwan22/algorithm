#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<pair<int, int>, pair<int, int>>> flower;
// flower {피는 날{m, d}, 지는 날{m, d}}

int n;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  pair<int, int> begin;
  pair<int, int> end;
  for (int i = 0; i < n; i++)
  {
    cin >> begin.first >> begin.second >> end.first >> end.second;
    flower.push_back({begin, end});
  }

  sort(flower.begin(), flower.end());

  int cnt = 0;
  pair<int, int> st = {3, 1};
  pair<int, int> en = {3, 1};
  pair<int, int> last = {12, 1};

  for (int i = 0; i < n; i++)
  {
    if (flower[i].first <= st)
    {
      if (flower[i].second > en)
        en = flower[i].second;
    }
    else
    {
      if (st == en)
        break;
      cnt++;
      i--;
      st = en;
    }
    if (en >= last)
      break;
  }

  if (en < last)
    cout << 0;
  else
    cout << ++cnt;

  return 0;
}