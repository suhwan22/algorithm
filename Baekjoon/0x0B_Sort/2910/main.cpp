#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(const pair<int, int> &a, const pair<int, int> &b)
{
  return a.first > b.first;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, c;
  cin >> n >> c;
  vector<pair<int, int>> arr;
  int input;
  for (int i = 0; i < n; i++)
  {
    cin >> input;
    bool flag = false;
    for (int i = 0; i < (int)arr.size(); i++)
    {
      if (arr[i].second == input)
      {
        flag = true;
        arr[i].first++;
        break ;
      }
    }
    if (!flag)
      arr.push_back({1, input});
  }

  stable_sort(arr.begin(), arr.end(), comp);

  for (auto p : arr)
  {
    for (int i = 0; i < p.first; i++)
      cout << p.second << " ";
  }

  return 0;
}