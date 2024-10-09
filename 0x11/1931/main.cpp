#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

pair<int, int> arr[100005] ={};

bool comp(const pair<int, int>& a, const pair<int, int>& b)
{
  if (a.second == b.second)
  {
    return a.first < b.first;
  }
  return a.second < b.second;
}

int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i].first >> arr[i].second;

  sort(arr, arr + n, comp);
  int cnt = 0;
  int t = 0;
  for (int i = 0; i < n; i++)
  {
    if (t > arr[i].first) continue;
    cnt++;
    t = arr[i].second;
  }
  cout << cnt;
}